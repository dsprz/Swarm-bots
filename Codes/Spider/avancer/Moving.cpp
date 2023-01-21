#include "Moving.h"

//Constructeur
Moving::Moving(){
}


/*
Pour utiliser la carte SSC-32 qui fait bouger les servomoteurs, on doit faire :
Serial.println(#pin Pposition Ttemps);
Avec -pin : le servomoteur accroché à ce pin que l'on veut faire bouger
     -position : la position que l'on veut que le servomoteur soit (entre 500 et 2500)
     -temps : le temps que met le servomoteur à aller à cette position
*/


//Fonction qui a une liste de pin et une position en entrée et qui pour chaque pin de la liste demander d'aller à une position
void Moving::bouger(int liste[],int positio, int taille){
  for(int i=0; i<taille; i++){
    Serial.print("#");
    Serial.print(liste[i]);
    Serial.print(" P");
    Serial.print(angle(liste[i],positio)); // on utilise angle pour que le déplacement soit symetrique
  }
  Serial.print(" T");
  Serial.println(500);
}

//Fonction qui a une liste de pin et une liste de position en entrée et qui pour chaque pin de la liste demander d'aller à une position
void Moving::bougerListe(int liste[],int positio[], int taille){
  //utiliser map(value, fromLow, fromHigh, toLow, toHigh) 
  for(int i=0; i<taille; i++){
    Serial.print("#");
    Serial.print(liste[i]);
    laPosition = map(positio[i],-90,90,500,2500); // map convertie des angles en entré (-90 à 90) à la position que demande la carte ssc-32 (500 à 2500)
    Serial.print(" P");
    Serial.print(angle(liste[i],positio[i]));
  }
  Serial.print(" T");
  Serial.println(500);
}

// Permet de faire tourner les servomoteurs de facon symetrique
double Moving::angle(int pin ,int positio){
  if (pin==0 or pin==4 or pin==8){
    return (3000-positio); //renvoie la symetrique par rapport à 1500);
  }
  else{return positio;}
}


//Fonction qui permet d'initialiser les servomoteurs à une certaine position pour ensuite pouvoir la faire avancer ( et tester que tout les servomoteurs marchent bien)
void Moving::initialisation(){
  bouger(pinDevant,1500,TAILLE6PIN);
  bouger(pinMilieu,1500,TAILLE6PIN);
  bouger(pinDerriere,1100,TAILLE6PIN);
  delay(1000);
  bouger(pinDerriere,2100,TAILLE6PIN);
  delay(1000);
  bouger(pinMilieu,1500,TAILLE6PIN);
  delay(1000);
}

//Fonction qui permet de faire le premier test de déplacement de l'araignée
void Moving::avancer(){
  bouger(pinMilieu1,1800,TAILLE3PIN);
  delay(100);
  int a[6] = {1200,1800,1200,1800,1200,1800};
  bougerListe(pinDevant,a,TAILLE6PIN);
  delay(100);
  bouger(pinMilieu1,1500,TAILLE3PIN);
  delay(100);

  //2ieme coté
  bouger(pinMilieu2,1800,TAILLE3PIN);
  delay(100);
  int b[6] = {1800,1200,1800,1200,1800,1200};
  bougerListe(pinDevant,b,TAILLE6PIN);
  delay(100);
  bouger(pinMilieu,1500,TAILLE6PIN);
  delay(100);
}

//fonction en test pour faire avancer l'araignée
void Moving::avancerV2(){
  int positio[18]={41,5,-2,-25,5,-2,0,5,-2,-5,5,-2,25,5,-2,-45,5,-2};
  bougerListe(toutPin,positio,TAILLETOUTPIN);
  delay(1000);
  int positio2[18]={20,40,-20,0,40,-20,-20,40,-20,16,40,-20,0,40,-20,-23,40,-20};
  bougerListe(toutPin,positio,TAILLETOUTPIN);
  delay(1000);
  int positio3[18]={-5,5,-2,25,5,-2,-45,5,-2,41,5,-2,-25,5,-2,0,5,-2};
  bougerListe(toutPin,positio,TAILLETOUTPIN);
}
