/* =================================================================
Projet GORRE
   Reception Infrarouge
  
  David Briand
  INSA Rennes  -  France
 
  build 1.0
  17.11.2013
  
  Notes:
        - Programme complet:
          =>Séquence de calibrage
          =>Séquence d'init de la communication
          =>Récupération des tensions issues des capteurs
          =>Seuillage des tensions des capteurs
          =>Encapsulation dans le type de trame prédéfini
          =>Envoie de la trame par liaison série
          
          ==> Ajout d'un timer permettant de mesurer le temps de balayage
          => Problème au niveau du calcul de nombres de trames en fonction du nombre
          de Capteurs
=================================================================== */
#include <avr/interrupt.h> 
#include <avr/io.h>    
#define enableM1 22 //Enable Mux 1 Pin 22 (digital)
#define enableM2 23 //Enable Mux 2 Pin 23 (digital)
#define sD0 24  //Selection 0 Mux Pin 24 (digital)
#define sD1 25  //Selection 1 Mux Pin 25 (digital)
#define sD2 26  //Selection 2 Mux Pin 26 (digital)
#define readM1 0 //Lecture du Mux 1 sur Analog 0
#define readM2 1 //Lecture du Mux 2 sur Analog 1
#define nbSensor 8
char startC='G'; //Start byte
char stopC ='E';  //Stop Byte
byte trame[256];
unsigned int sensorBin[8] = {000, 001, 010, 011, 100, 101, 110, 111};  //Sensors locations (8) 
unsigned int sensorMatrix[nbSensor];
unsigned int sensorMatrixReference[nbSensor];
int nbLoop;
unsigned long time;

  
/********Fonction d'initialisation **********/
void setup(){
    Serial.begin(9600); 
    pinMode(enableM1, OUTPUT);
    pinMode(enableM2, OUTPUT);
    pinMode(sD0, OUTPUT);
    pinMode(sD1, OUTPUT);
    pinMode(sD2, OUTPUT);
    digitalWrite(enableM1, HIGH);
    digitalWrite(enableM2, HIGH);
    //Calibration(sensorMatrixReference);
    interrupts();
}
/*********************************************/

/********Fonction MAIN *********************/
void loop(){  
  
  //Read the sensors' value
  for(int scan=0; scan<nbSensor; scan++)
  {    
      int sensorRow = sensorBin[scan];
      int s0 = sensorRow & 0x01;
      int s1 = (sensorRow>>1) & 0x01;
      int s2 = (sensorRow>>2) & 0x01;  
      
      digitalWrite(sD0, s0);
      digitalWrite(sD1, s1);
      digitalWrite(sD2, s2); 
      
      sensorMatrix[scan]=analogRead(readM1); //first mux
      //sensorMatrix[scan+nbSensor/2]=analogRead(readM2);  //2nd mux       
  }

  //Normalize sensor values to either 1 or 0  
  Thresholding(sensorMatrix);  
  delay(500);
  
  //Détermination du temps de balayage et d'envoi des données:
  /*time=micros();
  Serial.print("  "); 
  Serial.println(time);*/
}
