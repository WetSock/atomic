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
      digitalWrite(mainPin, HIGH); 
  };  
  if (command.indexOf("?turnOnParogenerator") > -1)
  {
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
  return;
}

void splitParams(String params){
  
}
