//// 
#include <Ethernet.h>   // Для связи с компом

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xE1, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 202);

EthernetServer server(80);
String controlString;


#define NUMLEDS 16      // кол-во светодиодов
#define COLOR_DEBTH 3
#include <microLED.h>   // Для ленты
microLED<NUMLEDS, 3, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;
microLED<NUMLEDS, 4, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip4;
microLED<NUMLEDS, 5, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip5;
microLED<NUMLEDS, 6, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip6;
microLED<NUMLEDS, 7, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip7;

strips = [strip, strip4, strip5, strip6, strip7];

void setup() {
  strip.setBrightness(90);
  // яркость применяется по CRT гамме
  // применяется при выводе .show() !

  // очистка буфера (выключить диоды, чёрный цвет)
  strip.clear();
  // применяется при выводе .show() !

  strip.show(); // вывод изменений на ленту


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  Serial.begin(9600);
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop(){
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        //read the HTTP request
        if (controlString.length() < 100) {
        
        // write characters to string
        controlString += c;
        }
        
        //if HTTP request has ended– 0x0D is Carriage Return \n ASCII
        if (c == 0x0D) {
          client.println("{ result: \"" + controlString + "\" }");
          
          delay(10);
          //stopping client
          client.stop();
          
          runCommand(controlString)
          //clearing string for next read
          controlString="";
        
        }
      }
    }
  }
}

void runCommand(command){
  if(command.indexOf("?setAqua") > -1)
  {
    strip.fill(mAqua);  // заливаем водой
    strip.show();         // выводим изменения
  }
  if(command.indexOf("?setYellow") > -1)
  {
    strip.fill(mYellow);  // заливаем НЕ водой
    strip.show();         // выводим изменения
  }
  if(command.indexOf("?turnOff") > -1) 
  {
    strip.clear();  // Выключаем
    strip.show();         // выводим изменения
  }
}

void splitParams(params){
  
}