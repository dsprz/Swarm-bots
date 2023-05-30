#ifndef _MOVING_
#define _MOVING_
#include <Arduino.h>
#define TAILLETOUTPIN 18
#define TAILLE6PIN 6

class Moving {
  public :
    int getVitesse();
    int setVitesse(int vitesse);

    int vitesse;  
    Moving(int vitesse); //Constructeur
    void testServos();
    void relever();
    void avancer(bool var);
    void reculer(bool var);
    void tournerGauche(bool var);
    void tournerDroite(bool var);
    void deplacement(int typeDeplacement);
    /* on a 0 : reculer 
            1 : avancer
            2 : gauche
            3 : droite
    */
    void checkGauche();
    void checkDroite();
    void checkMilieu();

    void positionNormal();
    void positionCommEssaim();
    
  private :
    void bouger(int liste,float positio);   
    void bougerListe(int liste[],float positio[], int taille,int temps);
    double angle(int pin, float positio); // permet de faire avancer en symetrique le robot
    int laPosition; // utilise pour utiliser la fonction angle dans le cpp
    //Ces listes sont utiles pour déplacer l'araignée. Elles corespondent à tous les pin accroché au servomoteur.
    const int toutPin[18] = {0,1,2,4,5,6,12,13,14,16,17,18,20,21,22,24,25,26};
    const int pinDevant[6] ={0,4,12,16,20,24};
    const int pinMilieu[6] ={1,5,13,17,21,25};
    const int pinDerriere[6] ={2,6,14,18,22,26};

    int const normTeta = 20;
    int const normBeta = 10;

    int temps = 600; 
    int tmp=200; // 200 c'est cool

    int beta=-20;
    int teta=-6;
    // test avec 2 listes
    const float listeAddition1[6]={15,-11,15,-15,11,-15};
    const float listeAddition2[6]={15,-11,15,15,-11,15};
    const float listeAddition3[6]={-15,11,-15,-15,11,-15};

    float listePosition[6]={16,-3,-12,25,10,-16};
    int listePositionBetaTeta[4]={normBeta,normTeta,normBeta,normTeta};
    float listeNormale[6]={16,-3,-12,25,10,-16};
    int listeNormaleBetaTeta[4]={normBeta,normTeta,normBeta,normTeta};
    int a=25;
    int b=10;
    float listePositionEssaim[18]={16,normBeta+a,normTeta+b,-3,normBeta-10,normTeta-60,-12,normBeta+a,normTeta+b,25,normBeta+a,normTeta,10,normBeta-10,normTeta-60,-16,normBeta+a,normTeta+b};

    bool oui=true; //permet de savoir lorsque les deux pattes sont au sol, laquel faire avancer (exmpliqué dans le .cpp)
    bool avantNormal=false;
    bool comparerListe();
    void leverPatte();
    void choixDeplacement(int typeDeplacement, bool var);
    void deplacementAction();
    float liste[18];
    int k;

};
#endif