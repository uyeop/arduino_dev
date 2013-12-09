void Init_Com()
{
   // Recieve data from BeagleBone and write it to a String
  while(Serial.available()){
    char inChar = (char)Serial.read();
    if (inChar == startC){
      Serial.print(startC);
      Serial.print(nbSensor);
      Serial.print(stopC);      
    }      
  }
  
}
