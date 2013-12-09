
#define Threshold 100

void Thresholding(unsigned int * sensors)
{
  /*sensors[] contains values between 0-1024 (arduino's raw ADC value for 0-5v)
    The thresholding value determine the state of each sensor, whether ON (1) or OFF (0)*/ 
    
  Serial.print("start");
  for(int scan=0; scan<(nbSensor); scan++)
  {
    
    if (sensors[scan] > Threshold)
        Serial.print(0);
    else
        Serial.print(1);
  }
   Serial.println("end");
}
