#include "Moving.h"
#include "Capteurs.h"
#include "Communication.h"
#include "SoftwareSerial.h"
int vitesse=1;
const char robotName = 'S';
Moving avancer = Moving(vitesse);
Capteurs capteurs = Capteurs();
Communication spiderRadio = Communication(robotName);

bool encore=true;
int duree = 6000;
unsigned long tempsAncien; 
unsigned long tempsActuel;


void setup() {
  Serial.begin(9600);
  spiderRadio.begin(9600);  
  avancer.positionNormal();
  delay(2000);
  /*spiderRadio.callMiniBot('K');
  spiderRadio.sendObjectToGrab(1);  */
  tempsAncien=millis(); // on initialise le temps ancien à maintenant.
}

void loop() {
  //while(encore){
    tempsActuel=millis();
    if ((tempsActuel-tempsAncien)>=duree){
      capteurs.mouvementVerrifObstacle();
      tempsAncien=millis();
      encore=false;
    }
    avancer.deplacement(1);
    /*if(!encore){
      for (int i=0;i<20;i++){
        avancer.deplacement(1);
      }
    }
  }
  
  encore=true;
  while(encore){
    tempsActuel=millis();
    if ((tempsActuel-tempsAncien)>=duree){
      capteurs.mouvementVerrifObstacle();
      tempsAncien=millis();
      encore=false;
    }
    avancer.deplacement(1);
    if(!encore){
      for (int i=0;i<20;i++){
        avancer.deplacement(1);
      }
    }
  }
  
  spiderRadio.resetAllBooleans();
  Serial.println(spiderRadio.getAbort());
  while(!spiderRadio.getAbort()){
    Serial.println("coucou");
    spiderRadio.callMiniBot('K');
    spiderRadio.sendObjectToGrab(1);
    spiderRadio.waitForHomePosition();
    avancer.positionCommEssaim();
  }*/
}



  //avancer.deplacement(0);
  /*Serial.println(tempsActuel-tempsAncien);                                  
  if ((tempsActuel-tempsAncien)>=duree){
    capteurs.mouvementVerrifObstacle();
    tempsAncien=millis();
  }*/
 /* 0 : reculer 
    1 : avancer
    2 : gauche
    3 : droite
   */ 
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