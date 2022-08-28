//// 
#include <Ethernet.h>   // Для связи с компом

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xE1, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 202);

EthernetServer server(80);
String controlString;


#define NUMLEDS 10      // кол-во светодиодов на лентах
#define COLOR_DEBTH 3
#include <microLED.h>   // Для ленты
microLED<NUMLEDS, 14, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip1; // Лента 1
microLED<NUMLEDS, 15, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip2; // Лента 2
microLED<NUMLEDS, 16, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip3; // Лента 3

const int allDiods[] = {3, 4, 5, 6, 7, 8, 9}; // Все диоды
const int mainLight[] = {3, 4}; // Основная подсветка

void setup() {
  // Включаем управление диодами
  int sizeOfArray = sizeof(allDiods) / sizeof(int);
  for ( int index = 0 ; index < sizeOfArray ; ++index ){
    pinMode(allDiods[index], OUTPUT); 
    digitalWrite(allDiods[index], LOW); 
  }  
  
  setupSPI();

  setupEthernet();
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
          
          runCommand(controlString);
          //clearing string for next read
          controlString="";
        
        }
      }
    }
  }
}

void setupSPI(){
  // задаем яркость лентам
  strip1.setBrightness(100);
  strip2.setBrightness(100);
  strip3.setBrightness(100);
  // очистка буфера (выключить диоды на лентах, чёрный цвет)
  strip1.clear();
  strip2.clear();
  strip3.clear();
  // применяется при выводе .show() !

  strip1.show(); // вывод изменений на ленту
  strip2.show(); // вывод изменений на ленту
  strip3.show(); // вывод изменений на ленту
  return;
}

void setupEthernet(){
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
  return;
}