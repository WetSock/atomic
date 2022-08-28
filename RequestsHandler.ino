void runCommand(String command){
  if (command.indexOf("?turnOff") > -1) 
  {
    strip1.clear();  // Выключаем
    strip2.clear();  // Выключаем
    strip3.clear();  // Выключаем
    strip1.show();   // выводим изменения
    strip2.show();   // выводим изменения
    strip3.show();   // выводим изменения

    int sizeOfArray = sizeof(allDiods) / sizeof(int);
    for ( int index = 0 ; index < sizeOfArray ; ++index ){
      pinMode(allDiods[index], OUTPUT); 
      digitalWrite(allDiods[index], LOW); 
    }  
  };
  if (command.indexOf("?setAqua") > -1)
  {
    strip1.fill(mAqua);  // заливаем водой
    strip1.show();         // выводим изменения
  };
  if (command.indexOf("?setYellow") > -1)
  {
    strip1.fill(mYellow);  // заливаем НЕ водой
    strip1.show();         // выводим изменения
  };
  if (command.indexOf("?turnOnMainLight") > -1)
  {
      int sizeOfArray = sizeof(mainLight) / sizeof(int);
      for ( int index = 0 ; index < sizeOfArray ; ++index ){
        digitalWrite(mainLight[index], HIGH); 
      }  
  };
  return;
}

void splitParams(String params){
  
}
