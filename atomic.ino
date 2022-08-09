//// 
#include <Ethernet.h>   // Для связи с компом

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xE1, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 202);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);



#define STRIP_PIN 7     // пин ленты
#define NUMLEDS 16      // кол-во светодиодов

#define COLOR_DEBTH 3

#include <microLED.h>   // Для ленты


microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;

void setup() {
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
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












  // ===================== БАЗОВЫЕ ШТУКИ =====================
  // яркость (0-255)
  strip.setBrightness(60);
  // яркость применяется по CRT гамме
  // применяется при выводе .show() !

  // очистка буфера (выключить диоды, чёрный цвет)
  strip.clear();
  // применяется при выводе .show() !

  strip.show(); // вывод изменений на ленту
  delay(1);     // между вызовами show должна быть пауза минимум 40 мкс !!!!

  // ===================== УСТАНОВКА ЦВЕТА =====================
  // Библиотека поддерживает два варианта работы с лентой:
  // изменение цвета конкретного диода при помощи функции set(диод, цвет)
  // или работа с массивом .leds[] "вручную"

  // запись strip.set(диод, цвет); равносильна strip.leds[диод] = цвет;

  // ------------- ОСНОВНЫЕ ФУНКЦИИ РАБОТЫ С ЦВЕТОМ ------------
  // указанные ниже функции врзвращают тип данных mData - сжатое представление цвета

  // mRGB(uint8_t r, uint8_t g, uint8_t b);   // цвет RGB, 0-255 каждый канал
  strip.set(0, mRGB(255, 0, 0));              // диод 0, цвет RGB (255 0 0) (красный)

  // mHSV(uint8_t h, uint8_t s, uint8_t v);   // цвет HSV, 0-255 каждый канал
  strip.leds[1] = mHSV(30, 255, 255);         // диод 1, (цвет 30, яркость и насыщенность максимум)

  // mHSVfast(uint8_t h, uint8_t s, uint8_t v); // цвет HSV, 0-255 каждый канал
  // расчёт выполняется чуть быстрее, но цвета не такие плавные
  strip.set(2, mHSVfast(90, 255, 255));         // диод 2, цвет 90, яркость и насыщенность максимум

  // mHEX(uint32_t color);        // WEB цвета (0xRRGGBB)
  strip.set(3, mHEX(0x30B210));   // диод 3, цвет HEX 0x30B210

  // в библиотеке есть 17 предустановленных цветов (макс. яркость)
  strip.leds[4] = mAqua;          // диод 4, цвет aqua

  // mWheel(int color);                   // цвета радуги 0-1530
  // mWheel(int color, uint8_t bright);   // цвета радуги 0-1530 + яркость 0-255
  strip.set(5, mWheel(1200));             // диод 5, цвет 1200

  // mWheel8(int color);                  // цвета радуги 0-255
  // mWheel8(int color, uint8_t bright);  // цвета радуги 0-255 + яркость 0-255
  //strip.set(6, mWheel8(100));     // диод 6, цвет 100 (диапазон 0-255 вдоль радуги)
  strip.set(6, mWheel8(100, 50));   // вторым параметром можно передать яркость

  // mKelvin(int kelvin);           // цветовая температура 1'000-40'000 Кельвин
  strip.set(7, mKelvin(3500));      // диод 7, цветовая температура 3500К

  strip.show();                     // выводим все изменения на ленту
  delay(2000);                      // задержка показа

  // ===================== ЗАЛИВКА =====================
  // Есть готовая функция для заливки всей ленты цветом - .fill()
  // принимает конвертированный цвет, например от функций цвета или констант выше
  strip.fill(mYellow);  // заливаем жёлтым
  strip.show();         // выводим изменения
  delay(2000);

  // также можно указать начало и конец заливки
  strip.fill(3, 7, mWheel8(100));   // заливаем ~зелёным с 3 по 6: счёт идёт с 0, заливается до указанного -1
  strip.show();                     // выводим изменения
  delay(2000);

  // ------------- РУЧНАЯ ЗАЛИВКА В ЦИКЛЕ ------------
  // Например покрасим половину ленты в один, половину в другой
  for (int i = 0; i < NUMLEDS / 2; i++) strip.leds[i] = mHSV(0, 255, 255);  	  // красный
  for (int i = NUMLEDS / 2; i < NUMLEDS; i++) strip.leds[i] = mHSV(80, 255, 255); // примерно зелёный
  strip.show(); // выводим изменения
  delay(2000);

  // ------------------------------------------
  // Для ускорения ручных заливок (ускорения расчёта цвета) можно создать переменную типа mData
  mData value1, value2;
  value1 = mHSV(60, 100, 255);
  value2 = mHSV(190, 255, 190);
  for (int i = 0; i < NUMLEDS; i++) {
    if (i < NUMLEDS / 2) strip.leds[i] = value1;  // первая половина ленты
    else strip.leds[i] = value2;                  // вторая половина ленты
  }
  strip.show(); // выводим изменения
  delay(2000);

  // ------------------------------------------
  // в цикле можно менять параметры генерации цвета. Например, сделаем радугу
  for (int i = 0; i < NUMLEDS; i++) strip.set(i, mWheel8(i * 255 / NUMLEDS)); // полный круг от 0 до 255
  strip.show(); // выводим изменения
  delay(2000);

  // или градиент от красного к чёрному (последовательно меняя яркость)
  for (int i = 0; i < NUMLEDS; i++) strip.set(i, mWheel8(0, i * 255 / NUMLEDS)); // полный круг от 0 до 255
  strip.show(); // выводим изменения
}

void loop(){
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        //read the HTTP request
        if (controlString.length() &lt; 100) {
        
        // write characters to string
        controlString += c;
        }
        
        //if HTTP request has ended– 0x0D is Carriage Return \n ASCII
        if (c == 0x0D) {
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();
          
          client.println("&lt;html&gt;");
          client.println("&lt;head&gt;");
          client.println("&lt;title&gt;The Geek Pub Arduino Ethernet Test Page&lt;/title&gt;");
          client.println("&lt;/head&gt;");
          client.println("&lt;body&gt;");
          client.println("&lt;img src=\"https://cdn.thegeekpub.com/wp-content/uploads/2018/01/the-geek-pub-big-logo-new.jpg\") style=\"width: 55%; margin-left: auto; margin-right: auto; display: block;\" /&gt;");
          client.println("
          
          &lt;h1 style=\"color: blue; font-family: arial; text-align: center;\"&gt;THE GEEK PUB ARDUINO ETHERNET TEST PAGE&lt;/h1&gt;
          
          ");
          client.println("
          
          &lt;h2 style=\"color: green; font-family: arial; text-align: center;\"&gt;LED ON/OFF FROM WEBPAGE&lt;/h2&gt;
          
          ");
          client.println("
          
          &lt;hr&gt;
          
          ");
          client.println("
          
          &lt;h2 style=\"color: blue; font-family: arial; text-align: center;\"&gt;&lt;a href=\"/?GPLED2ON\"\"&gt;Turn On The Blue LED&lt;/a&gt; - &lt;a href=\"/?GPLED2OFF\"\"&gt;Turn Off the Blue LED&lt;/a&gt;
          &lt;/h2&gt;
          
          ");
          client.println("&lt;/body&gt;");
          client.println("&lt;/html&gt;");
          
          delay(10);
          //stopping client
          client.stop();
          
          // control arduino pin
          if(controlString.indexOf("?GPLED2ON") &gt; -1) //checks for LEDON
          {
            digitalWrite(blueLEDPin, HIGH); // set pin high
          }
          else{
            if(controlString.indexOf("?GPLED2OFF") &gt; -1) //checks for LEDOFF
            {
              digitalWrite(blueLEDPin, LOW); // set pin low
            }
          }
          //clearing string for next read
          controlString="";
        
        }
      }
    }
  }
}