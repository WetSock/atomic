//// 
#include <Ethernet.h>   // Для связи с компом

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xE1, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 202);

EthernetServer server(80);
String controlString;


#define PARONUMLEDS 30      // кол-во светодиодов на лентах
#define COLOR_DEBTH 3
#include <microLED.h>   // Для ленты
#include <FastLEDsupport.h>
microLED<29, 14, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> reactorSPI; // Лента 1
microLED<PARONUMLEDS, 15, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> parogeneratorSPI; // Лента 2
microLED<5, 16, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> gznSPI; // Лента 3

const int parogeneratorPin = 3; // Парогенератор
const int nasosPin = 4; // ГЦН Главный циркуляционный насосный агрегат
const int saozPin = 5; // Гидроёмкости САОЗ
const int spzazPin = 6; // Гидроёмкости СПЗАЗ
const int kompensatorPin = 7; // Компенсатор давления
const int barboterPin = 8; // Бак-барботёр
const int lovushkaPin = 9; // Ловушка расплава
const int mainPin = 13; // Основная подсветка
const int allDiods[] = {3, 4, 5, 6, 7, 8, 9, 13}; // Все диоды
bool isParogenerate = false;
bool isAvaria = false;
unsigned long previousParogenerateTime = 0;
unsigned long previousAvariaTime = 0;
unsigned long avariaStartTime = 0;
const int parogeneRate = 40; // Частота изменения парогенерации в миллисекундах
const int crashRate = 20; // Частота изменения аварийных элементов в миллисекундах
int countNoise = 0;
int avariaStep = 0;

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

  if (isParogenerate && ((previousParogenerateTime + parogeneRate) < millis())) {
    previousParogenerateTime = millis();

    parogenerate();
  }
  if (isAvaria) { // Идёт авария
    if ((previousAvariaTime + crashRate) < millis()) {
      avariaLoop();
    }
  }
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
          Serial.println(controlString);
          
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
  reactorSPI.setBrightness(100);
  parogeneratorSPI.setBrightness(100);
  gznSPI.setBrightness(250);
  // очистка буфера (выключить диоды на лентах, чёрный цвет)
  reactorSPI.clear();
  parogeneratorSPI.clear();
  gznSPI.clear();
  // применяется при выводе .show() !

  reactorSPI.show(); // вывод изменений на ленту
  parogeneratorSPI.show(); // вывод изменений на ленту
  gznSPI.show(); // вывод изменений на ленту
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