
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
    reactorSPI.clear();  // Выключаем
    parogeneratorSPI.clear();  // Выключаем
    strip3.clear();  // Выключаем
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
    reactorSPI.fill(mWhite);  // заливаем водой
    reactorSPI.show();         // выводим изменения
  };  
  if (command.indexOf("?turnOnParogenerator") > -1)
  {
    parogeneratorSPI.fill(mWhite);  // заливаем водой
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
  if (command.indexOf("?changePower") > -1)
  {
    String params[3] = splitParams(command).params;
    int power = params[1].toInt();
    parogeneratorSPI.setBrightness(power);
    parogeneratorSPI.fill(mAqua); 
    parogeneratorSPI.show();         // выводим изменения
  }; 
  return;
}
