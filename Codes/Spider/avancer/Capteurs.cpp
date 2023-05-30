#include "Capteurs.h"
#include <Arduino.h>
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.1.1
#include <NewPing.h>
#include "Moving.h"
TFLI2C tflI2C;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Use this default I2C address
Moving moving = Moving(1);
Capteurs::Capteurs(){
}

//renvoie la distance de détection d’obstacle l’aide du capteur à ultrason HC-SR04
long Capteurs::capteurUltrason(){
  delay(29);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.println("UltraSon : "+String(sonar.convert_cm(uS))+" cm"); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  return(sonar.convert_cm(uS));
}

//renvoie la distance de détection d’obstacle l’aide du capteur à infrarouge LIDAR TF-Luna
int Capteurs::capteurIR(){
  if(tflI2C.getData(tfDist, tfAddr)){
     Serial.println("IR : "+String(tfDist)+" cm");
     return(tfDist);
  }
}

void Capteurs::mouvementVerrifObstacle(){
  moving.positionNormal();
  delay(200);
  moving.checkGauche();
  delay(1000);
  distanceObstacle(0);
  moving.checkDroite();
  delay(1000);
  distanceObstacle(1);
  moving.checkMilieu();
  delay(1000);
  distanceObstacle(2);
  mouvementSiObstacle();
  delay(500);
}
void Capteurs::distanceObstacle(int indice){
  // le capteur revoit 0 s'il capte pas (distance trop importante), il faut donc verrifier
  if ((capteurUltrason()<distanceMin && capteurUltrason()>0)){
    tableau[indice]=true;
  }
  else{
    tableau[indice]=false;
  }
}

void Capteurs::mouvementSiObstacle(){
  //Obstacle gauche droite et milieu oubien gauche et droite : tourne de 135 ° à droite
  if (tableau[0] && tableau[2]){
    combienDeplacer(3,31);
  } 
  //Obstacle gauche : tourne de 90 ° à droite
  else if (tableau[1] && tableau[2]){
    combienDeplacer(2,21);
  }
  //Obstacle gauche et milieu oubien que milieu : tourne de 90 ° à droite
  else if (tableau[1]){
    combienDeplacer(3,21);
  }
  //Obstacle gauche : tourne de 45 ° à droite
  else if (tableau[0]){
    combienDeplacer(3,10);
  }
  //Obstacle droite : tourne de 45 ° à gauche
  else if (tableau[2]){
    combienDeplacer(2,10);
  }
  
}
void Capteurs::combienDeplacer(int numeroDeplacement,int n){
  for (int i=0;i<n;i++){
    moving.deplacement(numeroDeplacement);
  }
}