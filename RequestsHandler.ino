
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
    isParogenerate = false;
    isAvaria = false;
    reactorSPI.clear();  // Выключаем
    parogeneratorSPI.clear();  // Выключаем
    gznSPI.clear();   // выводим изменения
    reactorSPI.show();   // выводим изменения
    parogeneratorSPI.show();   // выводим изменения
    gznSPI.show();   // выводим изменения

    int sizeOfArray = sizeof(allDiods) / sizeof(int);
    for ( int index = 0 ; index < sizeOfArray ; ++index ){
      pinMode(allDiods[index], OUTPUT); 
      digitalWrite(allDiods[index], LOW); 
    }  
  };
  if (command.indexOf("?turnOnMainLight") > -1)
  {
      turnOff();
      digitalWrite(mainPin, HIGH); 
  };  
  if (command.indexOf("?turnOnReactor") > -1)
  {
    turnOff();
    reactorSPI.setBrightness(100);
    reactorSPI.fill(mRed);
    reactorSPI.show();         // выводим изменения
  };  
  if (command.indexOf("?turnOnParogenerator") > -1)
  {
    turnOff();
    parogeneratorSPI.fill(mWhite); 
    parogeneratorSPI.show();         // выводим изменения
    isParogenerate = true;
  };  
  if (command.indexOf("?turnOnNasos") > -1)
  {
      turnOff();
      gznSPI.fill(mAqua); 
      gznSPI.show();   
      digitalWrite(nasosPin, HIGH); 
  };  
  if (command.indexOf("?turnOnSaoz") > -1)
  {
      turnOff();
      digitalWrite(saozPin, HIGH); 
  };  
  if (command.indexOf("?turnOnSpzaz") > -1)
  {
      turnOff();
      digitalWrite(spzazPin, HIGH); 
  };  
  if (command.indexOf("?turnOnKompensator") > -1)
  {
      turnOff();
      digitalWrite(kompensatorPin, HIGH); 
  };
  if (command.indexOf("?turnOnBarboter") > -1)
  {
      turnOff();
      digitalWrite(barboterPin, HIGH); 
  };
  if (command.indexOf("?turnOnLovushka") > -1)
  {
      turnOff();
      digitalWrite(lovushkaPin, HIGH); 
  };
  if (command.indexOf("?turnOnReactorRed") > -1)
  {
      turnOff();
      reactorSPI.setBrightness(100);
      reactorSPI.fill(mRed);  
      reactorSPI.show();         // выводим изменения
      gznSPI.setBrightness(100);
      gznSPI.fill(mAqua);  
      gznSPI.show();    
      parogeneratorSPI.setBrightness(100);
      parogeneratorSPI.fill(mWhite);  
      parogeneratorSPI.show();         // выводим изменения
      isParogenerate = true;
  }; 
  if (command.indexOf("?turnOnParogeneratorWhite") > -1)
  {
    parogeneratorSPI.setBrightness(100);
    parogeneratorSPI.fill(mWhite);  
    parogeneratorSPI.show();         // выводим изменения
    isParogenerate = true;
  }; 
  if (command.indexOf("?turnOnGZNAqua") > -1)
  {
    gznSPI.setBrightness(100);
    gznSPI.fill(mAqua);  
    gznSPI.show();         // выводим изменения
  }; 
  if (command.indexOf("?changePower") > -1)
  {
    String params[3] = splitParams(command).params;
    int power = params[1].toInt();
    reactorSPI.setBrightness(power);
    parogeneratorSPI.setBrightness(power);
    reactorSPI.show();         // выводим изменения
    parogeneratorSPI.show();         // выводим изменения
  }; 
  if (command.indexOf("?avaria") > -1)
  {
    gznOverdrive();

    parogeneratorSPI.setBrightness(250);
    parogeneratorSPI.show();         // выводим изменения
    reactorSPI.setBrightness(250);
    reactorSPI.show();         // выводим изменения

    avariaStep = 0;
    isAvaria = true;
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

    for (int i = 0; i < PARONUMLEDS; i++) {
      parogeneratorSPI.leds[i] = myGrad.get(inoise8(i * 20, countNoise), 255);
    }
    countNoise += 5; // Скорость, с которой меняется оттенок пара
    if (isParogenerate){ // Вдруг уже прервали парогенерацию?
      parogeneratorSPI.show();
    }
}

void avariaLoop(){
    avariaStep += 1;

    if (avariaStep == 30) { // Спустя какое-то время с начала аварии
      // Выключаем ГЦН
      gznSPI.clear();
      gznSPI.show();   
    }

    if (avariaStep < 250) {
      // постепенно уменьшаем яркость
      parogeneratorSPI.setBrightness(250 - avariaStep);
      parogeneratorSPI.show();         // выводим изменения
      reactorSPI.setBrightness(250 - avariaStep);
      reactorSPI.show();         // выводим изменения
    } else {
      isAvaria = false;
    }
}


void gznOverdrive(){
    gznSPI.setBrightness(250);
    gznSPI.fill(mAqua);  
    gznSPI.show();   
}

void turnOff(){
    isParogenerate = false;
    isAvaria = false;
    reactorSPI.clear();  // Выключаем
    parogeneratorSPI.clear();  // Выключаем
    gznSPI.clear();   // выводим изменения
    reactorSPI.show();   // выводим изменения
    parogeneratorSPI.show();   // выводим изменения
    gznSPI.show();   // выводим изменения

    int sizeOfArray = sizeof(allDiods) / sizeof(int);
    for ( int index = 0 ; index < sizeOfArray ; ++index ){
      pinMode(allDiods[index], OUTPUT); 
      digitalWrite(allDiods[index], LOW); 
    }  
}