//// 
#include <Ethernet.h>   // Для связи с компом

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xE1, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 202);

EthernetServer server(80);
String controlString;



#define STRIP_PIN 7     // пин ленты
#define NUMLEDS 16      // кол-во светодиодов
#define COLOR_DEBTH 3
#include <microLED.h>   // Для ленты
microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;

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
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("{ result: \"OK\" }");
          client.println();
          
          delay(10);
          //stopping client
          client.stop();
          
          // control arduino pin
          if(controlString.indexOf("?setAqua") > -1) //checks for LEDON
          {
            strip.fill(mAqua);  // заливаем водой
            strip.show();         // выводим изменения
          }
          else{
            if(controlString.indexOf("?setYellow") > -1) //checks for LEDOFF
            {
              strip.fill(mYellow);  // заливаем НЕ водой
              strip.show();         // выводим изменения
            }
          }
          //clearing string for next read
          controlString="";
        
        }
      }
    }
  }
}