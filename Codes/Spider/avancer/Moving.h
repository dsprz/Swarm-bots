#include <Arduino.h>
#define TAILLETOUTPIN 18
#define TAILLE6PIN 6
#define TAILLE3PIN 3

class Moving {
  public :
    Moving(); //Constructeur
    void initialisation();  
    void avancer();         
    void avancerV2();
    
  private :
    void bouger(int liste[],int positio, int taille);   
    void bougerListe(int liste[],int positio[], int taille);
    double angle(int pin, int positio); // permet de faire avancer en symetrique le robot
    
    int laPosition; // utilise pour utiliser la fonction angle dans le cpp

    //Ces listes sont utiles pour déplacer l'araignée. Elles corespondent à tous les pin accroché au servomoteur.
    int toutPin[18] = {0,1,2,4,5,6,8,9,10,16,17,18,20,21,22,24,25,26};
    int pinDevant[6] ={0,4,8,16,20,24};
    int pinMilieu[6] ={1,5,9,17,21,25};
    int pinDerriere[6] ={2,6,10,18,22,26};
    int pinDevant1[3]={0,8,20};
    int pinMilieu1[3]={1,9,21};
    int pinDerriere1[3]={2,10,22};
    int pinDevant2[3]={4,16,24};
    int pinMilieu2[3]={5,17,25};
    int pinDerriere2[3]={6,18,26};
};
