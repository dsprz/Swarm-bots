#include <Arduino.h>
#define TRIGGER_PIN 4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 5// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 250 // Maximum distance we want to ping for (in centimeters).
#define TAILLETABLEAU 3
#define distanceMin 50

class Capteurs{
 public : 
    Capteurs(); 
    long capteurUltrason();
    int capteurIR();
    void mouvementVerrifObstacle();
    void mouvementSiObstacle();
    
  private :
    void distanceObstacle(int indice);
    bool tableau[3];
    void combienDeplacer(int numeroDeplacement,int n);    
};
