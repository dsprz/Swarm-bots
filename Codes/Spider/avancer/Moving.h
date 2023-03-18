#ifndef _MOVING_
#define _MOVING_
#include <Arduino.h>
#define TAILLETOUTPIN 18
#define TAILLE6PIN 6
#define TAILLE3PIN 3

class Moving {
  public :
    Moving(); //Constructeur
    void initialisation();  
    void avancer1();    // le paramètre verrifie si avant l'araignée reculait ou pas
    void avancer2();
    void reculer1();    // le paramètre verrifie si avant l'araignée avancait ou pas
    void reculer2();
    void tournerGauche1();
    void tournerGauche2();
    void tournerDroite1();
    void tournerDroite2();

    void checkGauche();
    void checkDroite();
    void checkMilieu();

    void positionNormal();
    
  private :
    void bouger(int liste,float positio);   
    void bougerListe(int liste[],float positio[], int taille,int temps);
    double angle(int pin, float positio); // permet de faire avancer en symetrique le robot
    int laPosition; // utilise pour utiliser la fonction angle dans le cpp

    //Ces listes sont utiles pour déplacer l'araignée. Elles corespondent à tous les pin accroché au servomoteur.
    int pinProbleme=15;
    int toutPin[18] = {0,1,2,4,5,6,pinProbleme,9,10,16,17,18,20,21,22,24,25,26};
    int pinDevant[6] ={0,4,pinProbleme,16,20,24};
    int pinMilieu[6] ={1,5,9,17,21,25};
    int pinDerriere[6] ={2,6,10,18,22,26};
    int pinDevant1[3]={0,pinProbleme,20};
    int pinMilieu1[3]={1,9,21};
    int pinDerriere1[3]={2,10,22};
    int pinDevant2[3]={4,16,24};
    int pinMilieu2[3]={5,17,25};
    int pinDerriere2[3]={6,18,26};

    int normTeta = 20;
    int normBeta = 10;

    int temps = 600; 

    int d1;
    int m1;
    int g1;
};
#endif