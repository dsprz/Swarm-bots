#include "Moving.h"

//Constructeur
Moving::Moving(int vitesse){
  setVitesse(vitesse);
}
int Moving::setVitesse(int vitesse){
  this->vitesse=vitesse;
}
int Moving::getVitesse(){
  return (this->vitesse);
}

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
  //renvoie la symetrique par rapport à 1500) pour les servotmoeurs de droite;
  if (pin==16 or pin==20 or pin==24){
    return (3000-positio);
  }
  if (pin==2 or pin==6 or pin==10 or pin==18 or pin==22 or pin==26){
    return (positio + 400);
  }
  //les servo moteurs ne sont pas exacement pareil
  if(pin==25){return (positio+40);}
  if(pin==14){return (positio-100);}
  if(pin==21){return (positio+90);}
  if(pin==17){return (positio-20);}

  return positio;
}

//Fonction qui permet d'initialiser les servomoteurs à une certaine position pour ensuite pouvoir la faire avancer ( et tester que tout les servomoteurs marchent bien)
void Moving::testServos(){
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
void Moving::relever(){
  for (int i=0; i<6 ; i++){
    listePosition[i]=listeNormale[i];
  }
  for (int i=0;i<4;i++){
    listePositionBetaTeta[i]=0;
  }
  deplacementAction();
  bougerListe(toutPin,liste,TAILLETOUTPIN,temps);
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
  //Si toute les pattes touchent le sol, on les leves pour le déplacement
  if (listePosition[0]==normBeta && listePosition[2]==normBeta && !comparerListe()){
    leverPatte();
  }
  for (int i=0; i<6 ; i++){
    listePosition[i]=listeNormale[i];
  }
  for (int i=0;i<4;i++){
    listePositionBetaTeta[i]=listeNormaleBetaTeta[i];
  }
  deplacementAction();
  bougerListe(toutPin,liste,TAILLETOUTPIN,temps);
}


void Moving::avancer(bool var){
  if (var){
    for (int i=0; i<6; i++){
      listePosition[i]+=listeAddition1[i]*vitesse;
    }
  }
  else{
    for (int i=0; i<6; i++){
      listePosition[i]-=listeAddition1[i]*vitesse;
    }
  }
}
void Moving::reculer(bool var){
 if (var){
    for (int i=0; i<6; i++){
      listePosition[i]-=listeAddition1[i]*vitesse;
    }
  }
  else{
    for (int i=0; i<6; i++){
      listePosition[i]+=listeAddition1[i]*vitesse;
    }
  }
}
void Moving::tournerGauche(bool var){
  if (var){
    for (int i=0; i<6; i++){
      listePosition[i]+=listeAddition2[i]*vitesse;
    }
  }
  else{
    for (int i=0; i<6; i++){
      listePosition[i]-=listeAddition2[i]*vitesse;
    }
  }
}
void Moving::tournerDroite(bool var){
  if (var){
    for (int i=0; i<6; i++){
      listePosition[i]+=listeAddition3[i]*vitesse;
    }
  }
  else{
    for (int i=0; i<6; i++){
      listePosition[i]-=listeAddition3[i]*vitesse;
    }
  }
}
//permet de savoir si le déplacement est de reculer(0), d'avancer (1), de tourner à gauche(2) oubien de tourner à droite(3)
void Moving::choixDeplacement(int typeDeplacement,bool var){
  if (var){
    listePositionBetaTeta[0]+=beta;
    listePositionBetaTeta[1]+=teta;
  }
  else{
    listePositionBetaTeta[2]+=beta;
    listePositionBetaTeta[3]+=teta;
  }
  switch (typeDeplacement){
    case 0 :
      avancer(var);
      break;
    case 1 :
      reculer(var);
      break;
    case 2 :
      tournerGauche(var);
      break;
    case 3 :
      tournerDroite(var);
      break;
  }
}
void Moving::deplacement(int typeDeplacement){
  //on verrifie si avant le robot était dans la position normal
  if(comparerListe()){
    leverPatte();
    avantNormal=true;
  }
  //si la 1er patte est au sol : 
  // Oui permet que ca marche exemple : les deux sont aux sol, pour savoir lequel doit avancer
  else if (listePositionBetaTeta[0]<=normBeta && oui){
    choixDeplacement(typeDeplacement,0);
  }
  //si la 2ieme patte est au sol
  else if (listePositionBetaTeta[2]<=normBeta && !oui){
    choixDeplacement(typeDeplacement,1);
  }
  //Si la patte est monté au maximum, change la liste pour que la patte descende après
  if (!avantNormal){
    if (listePositionBetaTeta[0]>=normBeta+40||listePositionBetaTeta[2]>=normBeta+40){ 
      beta=-20*vitesse;
      teta=-6*vitesse;  
    }
  }
  else{
    avantNormal=false;
  }
  //Si toute les pattes touche le sol, alors les angles beta et teta devront être positif pour avancer
  if ((listePositionBetaTeta[0]<=normBeta)&&(listePositionBetaTeta[2]<=normBeta)){
    beta=20*vitesse;
    teta=6*vitesse;
    oui=!oui;
  } 
  //change la position de l'araignée
  deplacementAction();
  bougerListe(toutPin,liste,TAILLETOUTPIN,tmp);
}

void Moving::leverPatte(){
  listePositionBetaTeta[2]=normBeta+40;
  listePositionBetaTeta[3]=normTeta+12;
}

bool Moving::comparerListe(){
  for (int i=0;i<6;i++){
    if (listePosition[i]!=listeNormale[i]){
      return false;
    }
  }
  if(listePositionBetaTeta[0]!=listeNormaleBetaTeta[0]||listePositionBetaTeta[2]!=listeNormaleBetaTeta[2]){
    return false;
  }  
  return true;
}

void Moving::deplacementAction(){
  k=0;
  for (int i=0;i<18;i++){
    if(i%3==0){
      liste[i]=listePosition[k];
      k+=1;
    }
    else if (i%3==1 && i%2==0){
        liste[i]=listePositionBetaTeta[2];
    }
    else if (i%3==1 && i%2==1){
      liste[i]=listePositionBetaTeta[0];
    }
    else if (i%3==2 && i%2==0){
      liste[i]=listePositionBetaTeta[1];
    }
    else{
      liste[i]=listePositionBetaTeta[3];
    }
  }
}
 
void Moving::positionCommEssaim(){
  positionNormal();
  delay(100);
  bougerListe(toutPin,listePositionEssaim,TAILLETOUTPIN,temps);
}
