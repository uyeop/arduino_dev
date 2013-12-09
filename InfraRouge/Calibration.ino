void Calibration(unsigned int * reference)
{
  for(int scan=0; scan<(nbSensor); scan++){
    nbLoop=nbSensor/8;
    sensorMatrixReference[scan]=50;
  }
    for(int i=0; i<(nbLoop); i++){
    //nbLoop=nbSensor/8;
    trame[i]=0x00;
  }
  //Serial.println(nbLoop);
}
