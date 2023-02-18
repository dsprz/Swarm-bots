#include "Moving.h"

//Constructeur
Moving::Moving(){}

/*
Pour utiliser la carte SSC-32 qui fait bouger les servomoteurs, on doit faire :
Serial.println(#pin Pposition Ttemps);
Avec -pin : le servomoteur accroché à ce pin que l'on veut faire bouger
     -position : la position que l'on veut que le servomoteur soit (entre 500 et 2500)
     -temps : le temps que met le servomoteur à aller à cette position
*/

//Fonction qui a une liste de pin et une position en entrée et qui pour chaque pin de la liste demander d'aller à une position
void Moving::bouger(int liste,float positio){
    Serial.print("#");
    Serial.print(liste);
    Serial.print(" P");
    Serial.print(angle(liste,positio)); // on utilise angle pour que le déplacement soit symetrique
  Serial.print(" T");
  Serial.println(500);
}

//Fonction qui a une liste de pin et une liste de position en entrée et qui pour chaque pin de la liste demander d'aller à une position
void Moving::bougerListe(int liste[],float positio[], int taille){
  //utiliser map(value, fromLow, fromHigh, toLow, toHigh) 
  for(int i=0; i<taille; i++){
    Serial.print("#");
    Serial.print(liste[i]);
    laPosition = map(positio[i],-90,90,500,2500); // map convertie des angles en entré (-90 à 90) à la position que demande la carte ssc-32 (500 à 2500)
    Serial.print(" P");
    Serial.print(angle(liste[i],laPosition));
  }
  Serial.print(" T");
  Serial.println(600);
}

// Permet de faire tourner les servomoteurs de facon symetrique
double Moving::angle(int pin ,float positio){
  if (pin==16 or pin==20 or pin==24){
    return (3000-positio); //renvoie la symetrique par rapport à 1500);
  }
  else if (pin==2 or pin==6 or pin==10 or pin==18 or pin==22 or pin==26){
    return (positio + 400);
  }
  return positio;
}


//Fonction qui permet d'initialiser les servomoteurs à une certaine position pour ensuite pouvoir la faire avancer ( et tester que tout les servomoteurs marchent bien)
void Moving::initialisation(){
  for (int i=0; i<TAILLE6PIN;i++){
    bouger(pinDevant[i],2000);
    delay(500);
    bouger(pinDevant[i],1500);
    delay(500);
    bouger(pinMilieu[i],2000);
    delay(500);
    bouger(pinMilieu[i],1500);
    delay(500);
    bouger(pinDerriere[i],2000);
    delay(500);
    bouger(pinDerriere[i],1500);
    delay(500);
    /*bouger(pinProbleme,1200);
    bouger(4,1200);
    bouger(0,1200);
    delay(600);
    bouger(pinProbleme,1800);
    bouger(4,1800);
    bouger(0,1800);
    delay(600);*/
  }
  /*
  bouger(pinDevant,1500,TAILLE6PIN);
  bouger(pinMilieu,1500,TAILLE6PIN);
  bouger(pinDerriere,1500,TAILLE6PIN);
  delay(1000);
  bouger(pinMilieu,1500,TAILLE6PIN);
  delay(1000);*/
}

//fonction en test pour faire avancer l'araignée
void Moving::avancer1(){
    float positio2[18]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
    bougerListe(toutPin,positio2,TAILLETOUTPIN);
    delay(300);
  
  float positio[18]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio,TAILLETOUTPIN);
  delay(300);
}
void Moving::avancer2(){
    float positio2[18]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
    bougerListe(toutPin,positio2,TAILLETOUTPIN);
    delay(300);   
  
  float positio1[18]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio1,TAILLETOUTPIN);
  delay(300);
  
}

void Moving::reculer1(){  
    float positio2[18]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
    bougerListe(toutPin,positio2,TAILLETOUTPIN);
    delay(300);
  
  float positio1[18]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio1,TAILLETOUTPIN);
  delay(300);
  
}
void Moving::reculer2(){
    float positio2[18]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
    bougerListe(toutPin,positio2,TAILLETOUTPIN);
    delay(300);
 
  float positio1[18]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio1,TAILLETOUTPIN);
  delay(300);
}

void Moving::tournerGauche1(){
    float positio1[18]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
    bougerListe(toutPin,positio1,TAILLETOUTPIN);
    delay(300);
  
  float positio2[18]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio2,TAILLETOUTPIN);
  delay(300);
}
void Moving::tournerGauche2(){
    float positio1[18]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
    bougerListe(toutPin,positio1,TAILLETOUTPIN);
    delay(300);
  
  float positio2[18]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio2,TAILLETOUTPIN);
  delay(300);
}

void Moving::tournerDroite1(){
    float positio1[18]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
    bougerListe(toutPin,positio1,TAILLETOUTPIN);
    delay(300);
  
  float positio2[18]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio2,TAILLETOUTPIN);
  delay(300);
}
void Moving::tournerDroite2(){
    float positio1[18]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
    bougerListe(toutPin,positio1,TAILLETOUTPIN);
    delay(300);
  
  float positio2[18]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio2,TAILLETOUTPIN);
  delay(300);
}
