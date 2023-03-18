#include "Moving.h"
#include "Capteurs.h"
Moving avancer = Moving();
Capteurs capteurs = Capteurs();
bool encore=true;
int duree = 8000;
unsigned long tempsAncien; 
unsigned long tempsActuel;

void setup() {
  Serial.begin(9600);  
  //avancer.initialisation();
  tempsAncien=millis(); // on initialise le temps ancien à maintenant.
}

void loop() {
  tempsActuel=millis();                                   
  if ((tempsActuel-tempsAncien)<=duree){
    capteurs.obstacle();
    tempsAncien=tempsActuel;
  }
  avancer.avancer1();
  avancer.avancer2();
  
}


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
  }*/