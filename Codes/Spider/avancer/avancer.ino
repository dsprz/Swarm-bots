#include "Moving.h"
Moving moving = Moving();
bool encore=true;

void setup() {
  Serial.begin(9600);
  moving.initialisation();
}

void loop() {
  //moving.initialisation();
  moving.avancer1();
  moving.avancer2();
 /* 
  while(Serial.available()) {
      int lu = Serial.read();
      lu = lu-48;
      if (lu==0){
        if (encore){
          moving.avancer1();
          encore=false;}
        else{
          moving.avancer2();
          encore=true;}
      }
      else if (lu==1){
        if (!encore){
          moving.tournerDroite1();
          encore=true;}
        else{
          moving.tournerDroite2();
          encore=false;}
      }
      else if (lu==2){
        if (encore){
          moving.tournerGauche1();
          encore=false;}
        else{
          moving.tournerGauche2();
          encore=true;}
      }
      else if (lu==3){
        if (encore){
          moving.reculer1();
          encore=false;}
        else{
          moving.reculer2();
          encore=true;}
      }   
  }
  */
  /*
  for(int i=0; i<=4;i++){
    moving.avancer1();
    moving.avancer2();
  }
  for(int i=0; i<=4;i++){
    moving.reculer1();
    moving.reculer2();
  }
  for(int i=0; i<=4;i++){
    moving.tournerGauche1();
    moving.tournerGauche2();
  }
  for(int i=0; i<=4;i++){
    moving.tournerDroite1();
    moving.tournerDroite2();
  }*/
  
}
