

void Thresholding(unsigned int sensors[nbSensor])
{
  Serial.print("start");
  for(int scan=0; scan<(nbSensor); scan++)
  {
    Serial.print(sensors[scan]);
  }
   Serial.println("end"); 
   delay(500);
   
}
