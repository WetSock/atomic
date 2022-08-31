
struct Array3 {
    String params[3];
};

Array3 splitParams(String url, String delimeter = "&"){

    Serial.print("Обрабатываю запрос: ");
    Serial.println(url);

    // Убираем всё до параметров
    int start = url.indexOf("?");
    String params = url.substring(start + 1, url.length());

    // Заполняем всё в массив
    Array3 result;

    start = 0;
    int end = params.indexOf(delimeter);
    int index = 0;
    while (end != -1) {
        result.params[index] = params.substring(start, end);
        Serial.print("Нашел параметр: ");
        Serial.println(result.params[index]);

        start = end + 1;
        end = params.indexOf(delimeter, start);
        index++;
    }

    result.params[index] = params.substring(start, end);
    Serial.print("Нашел параметр: ");
    Serial.println(result.params[index]);

    

    return result;
}


void runCommand(String command){
  if (command.indexOf("?turnOff") > -1) 
  {
    reactorSPI.setBrightness(100);
    parogeneratorSPI.setBrightness(100);
    reactorSPI.clear();  // Выключаем
    parogeneratorSPI.clear();  // Выключаем
    reactorSPI.show();   // выводим изменения
    parogeneratorSPI.show();   // выводим изменения
    strip3.show();   // выводим изменения

    int sizeOfArray = sizeof(allDiods) / sizeof(int);
    for ( int index = 0 ; index < sizeOfArray ; ++index ){
      pinMode(allDiods[index], OUTPUT); 
      digitalWrite(allDiods[index], LOW); 
    }  
  };
  if (command.indexOf("?turnOnMainLight") > -1)
  {
      digitalWrite(mainPin, HIGH); 
  };  
  if (command.indexOf("?turnOnReactor") > -1)
  {
    reactorSPI.fill(mAqua);
    reactorSPI.show();         // выводим изменения
  };  
  if (command.indexOf("?turnOnParogenerator") > -1)
  {
    parogeneratorSPI.fill(mWhite); 
    parogeneratorSPI.show();         // выводим изменения
    digitalWrite(parogeneratorPin, HIGH); 
  };  
  if (command.indexOf("?turnOnNasos") > -1)
  {
      digitalWrite(nasosPin, HIGH); 
  };  
  if (command.indexOf("?turnOnSaoz") > -1)
  {
      digitalWrite(saozPin, HIGH); 
  };  
  if (command.indexOf("?turnOnSpzaz") > -1)
  {
      digitalWrite(spzazPin, HIGH); 
  };  
  if (command.indexOf("?turnOnKompensator") > -1)
  {
      digitalWrite(kompensatorPin, HIGH); 
  };
  if (command.indexOf("?turnOnBarboter") > -1)
  {
      digitalWrite(barboterPin, HIGH); 
  };
  if (command.indexOf("?turnOnLovushka") > -1)
  {
      digitalWrite(lovushkaPin, HIGH); 
  };
  if (command.indexOf("?turnOnReactorRed") > -1)
  {
    reactorSPI.fill(mRed);  
    reactorSPI.show();         // выводим изменения
  }; 
  if (command.indexOf("?turnOnParogeneratorWhite") > -1)
  {
    parogeneratorSPI.fill(mWhite);  
    parogeneratorSPI.show();         // выводим изменения
  }; 
  if (command.indexOf("?changePower") > -1)
  {
    String params[3] = splitParams(command).params;
    int power = params[1].toInt();
    reactorSPI.setBrightness(power);
    parogeneratorSPI.setBrightness(power);
    reactorSPI.fill(mRed); 
    parogeneratorSPI.fill(mWhite); 
    reactorSPI.show();         // выводим изменения
    parogeneratorSPI.show();         // выводим изменения
  }; 
  return;
}

void parogenerate(){
    mGradient<5> myGrad;
    myGrad.colors[0] = mBlack;
    myGrad.colors[1] = mWhite;
    myGrad.colors[2] = mBlack;
    myGrad.colors[3] = mWhite;
    myGrad.colors[4] = mBlack;

    for (int i = 0; i < NUMLEDS; i++) {
      strip3.leds[i] = myGrad.get(inoise8(i * 20, countNoise), 255);
    }
    countNoise += 5; // Скорость, с которой меняется оттенок пара
    strip3.show();
}