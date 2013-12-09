/*
 created 25 Nov. 2013
 by Umar 
 
 Test sending frames through serial port
*/

int state;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  //Serial1.begin(9600);
}

void loop() {

  Serial.print("start");
  
  for (int i=0; i<8; i++)
  {
     //Send the sensor's position
     //Serial.print(i);
     
     //generate random state for the sensor
     if (random(0,10) > 5)
       state = 1;
     else
       state = 0;
    
     //send the state of the sensor         
     Serial.print(state);
     //Serial.print("\n");
  }
  Serial.print("end");
  //Serial.write("\n");
  delay(3000);
}
