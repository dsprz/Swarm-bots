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
void Moving::bougerListe(int liste[],float positio[], int taille, int temps){
  //utiliser map(value, fromLow, fromHigh, toLow, toHigh) 
  for(int i=0; i<taille; i++){
    Serial.print("#");
    Serial.print(liste[i]);
    laPosition = map(positio[i],-90,90,500,2500); // map convertie des angles en entré (-90 à 90) à la position que demande la carte ssc-32 (500 à 2500)
    Serial.print(" P");
    Serial.print(angle(liste[i],laPosition));
  }
  Serial.print(" T");
  Serial.println(temps);
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
  }
}

//fonction en test pour faire avancer l'araignée
void Moving::avancer1(){
  float positio2[18]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio[18]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio,TAILLETOUTPIN,temps);
  delay(300);
}
void Moving::avancer2(){
  float positio2[TAILLETOUTPIN]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);   
  
  float positio1[TAILLETOUTPIN]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
}

void Moving::reculer1(){  
  float positio2[TAILLETOUTPIN]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio1[TAILLETOUTPIN]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
}
void Moving::reculer2(){
  float positio2[TAILLETOUTPIN]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
 
  float positio1[TAILLETOUTPIN]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
}

void Moving::tournerGauche1(){
  float positio1[TAILLETOUTPIN]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio2[TAILLETOUTPIN]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
}
void Moving::tournerGauche2(){
  float positio1[TAILLETOUTPIN]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio2[TAILLETOUTPIN]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
}

void Moving::tournerDroite1(){
  float positio1[TAILLETOUTPIN]={15.5,normBeta,normTeta,-2.5,normBeta+40,normTeta+12,-12,normBeta,normTeta,24.5,normBeta+40,normTeta+12,11,normBeta,normTeta,-15.5,normBeta+40,normTeta+12};  //position 6
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio2[TAILLETOUTPIN]={46,normBeta,normTeta,-25,normBeta,normTeta,18,normBeta,normTeta,54,normBeta,normTeta,-10,normBeta,normTeta,15,normBeta,normTeta};   // position 0
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
}
void Moving::tournerDroite2(){
  float positio1[TAILLETOUTPIN]={15.5,normBeta+40,normTeta+12,-2.5,normBeta,normTeta,-12,normBeta+40,normTeta+12,24.5,normBeta,normTeta,11,normBeta+40,normTeta+12,-15.5,normBeta,normTeta};  //position 6
  bougerListe(toutPin,positio1,TAILLETOUTPIN,temps);
  delay(300);
  
  float positio2[TAILLETOUTPIN]={-15,normBeta,normTeta,20,normBeta,normTeta,-42,normBeta,normTeta,-5,normBeta,normTeta,32,normBeta,normTeta,-46,normBeta,normTeta};      //position 14
  bougerListe(toutPin,positio2,TAILLETOUTPIN,temps);
  delay(300);
}

void Moving::checkGauche(){
  float positio[TAILLE6PIN]={40,40,40,-40,-40,-40};
  bougerListe(pinDevant,positio,TAILLE6PIN,temps);
}

void Moving::checkDroite(){
  float positio[TAILLE6PIN]={-40,-40,-40,40,40,40};
  bougerListe(pinDevant,positio,TAILLE6PIN,temps);
}

void Moving::checkMilieu(){
  positionNormal();
  
}

void Moving::positionNormal(){
  float positio[TAILLETOUTPIN]={0,normBeta,normTeta,0,normBeta,normTeta,0,normBeta,normTeta,0,normBeta,normTeta,0,normBeta,normTeta,0,normBeta,normTeta};
  bougerListe(toutPin,positio,TAILLETOUTPIN,temps);
}

/*
//test pour de nouvelles fonction pour bouger

m1 = normBeta à normBeta+40 = 40 // division par 10

b1 = normTeta à normTeta+12 = 12 // division par 3

f1 = 46 à -15 = 61 // pareil que f4 donc 60 division par -15

f2 = -25 à 20 = 45 // pareil que f5 donc 44 division par 11

f3 = 18 à -42 = 60 // pare  il que f6 donc 60 division par -15

f4 = -5 à 54 = 59 // par +15

f5 = 32 à -10 = 42 // par -11

f6 = -46 à 15 = 61 // par +15

float listeAddition1[18]={-15,0,0,11,beta,teta,-15,0,0,15,beta,teta,-11,0,0,15,beta,teta};
float listeAddition2[18]={-15,beta,teta,11,0,0,-15,beta,teta,15,0,0,-11,beta,teta,15,0,0};
void Moving::avancer(){
  //si la 1er patte est au sol : 
  if (listePosition[2]==normBeta){
    for (int i=0; i<18; i++){
      listePosition[i]+=listeAddition1[i];
    }
  }
  //si la 2ieme patte est au sol
  else if (listePosition[5]==normBeta){
    listePosition[i]+=listeAddition2[i];
  }
  //Si la patte est monté au maximum, change la liste pour que la patte descende après
  if (listePosition[2]==normBeta+40||listePosition[5]==normBeta+40){
    beta=-10;
    teta=-3;
  }
  //Si toute les pattes touche le sol, alors les angles beta et teta devront être positif pour avancer
  if (listePosition[2]==normBeta)&&(listePosition[5]==normBeta){
    listePosition=listeNormale; // on remet la liste en normal au cas ou
    beta=10;
    teta=3;
  } 
  //change la position de l'araignée
  bougerListe(toutPin,listePosition,TAILLETOUTPIN,temps); 
  delay(100); 
}

void Moving::reculer(){
  //comme on recule, cest la même chose que avancer mais quand la patte monte, on doit dessendre et les positions sont invercées.
  if (listePosition[2]==normBeta){
    for (int i=0; i<18; i++){
      listePosition[i]+=-listeAddition1[i];
    }
  }
  else(listePosition[5]==normBeta){
    listePosition[i]+=-listeAddition2[i];
  }
  //Si la patte est monté au maximum, change la liste pour que la patte descende après
  if (listePosition[2]==normBeta+40||listePosition[5]==normBeta+40){
    beta=10;
    teta=3;
  }
  //Si toute les pattes touche le sol, alors les angles beta et teta devront augmenter pour avancer
  if (listePosition[2]==normBeta)&&(listePosition[5]==normBeta){
    beta=-10;
    teta=-3;
    listePosition=listeNormale;
  } 
  bougerListe(toutPin,listePosition,TAILLETOUTPIN,temps);
}
void Moving::positionNormal(){

}
void Moving::tournerGauche(){

}

// ATTENTION PAS OUBLIER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// quand on tourner apres on dessend ! ! ! ! ! ! ! ! pas oublier ca 
*/  