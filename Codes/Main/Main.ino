#include <Pixy2.h>
#include <Servo.h>
#include <NewPing.h>
#include <SoftwareSerial.h>

const int gripperServoPin = 3;
const int leftWheelPin = 5;
const int rightWheelPin = 6;
const int HC12_RXD = 8;
const int HC12_TXD = 9;
const int trigger = 14;
const int echo = 15;
const int maxDistance = 350; //cm
//float stickGlueHeight = 6 ; //cm
float distance; //cm

bool grabbing = false; //Pour l'instant ces deux bools ne servent à rien
bool grabbed = false;

Pixy2 pixy;
Servo gripperServo;
Servo rightWheel;
Servo leftWheel;
NewPing distanceSensor(trigger, echo, maxDistance);
SoftwareSerial HC12(HC12_TXD, HC12_RXD);

//Fonctions de déplacement du robot
void fullSpeed()
{
  rightWheel.write(0);
  leftWheel.write(180);
}

void stop()
{
  rightWheel.write(90);
  leftWheel.write(270);
}

void turnRight()
{
  rightWheel.write(90);
  leftWheel.write(180);
}

void turnLeft()
{
  rightWheel.write(0);
  leftWheel.write(270);
}

void avoidObstacle(float distance)
//Le robot tourne à droite pour éviter un obstacle
{
  if(distance > 20) 
  {
    fullSpeed();
    Serial.println("Full speed");
  }
  else 
  {
    turnRight(); 
    Serial.println("Turn Right");
  }
}
void pixyPrintBlockInfos()
//Affiche les informations utiles de la Pixy pour la détection d'objets
{
    for(int i = 0; i < pixy.ccc.numBlocks; ++i)
    {
      Serial.print(" block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    } 
}

void grabTheObject()
//Actionne le servomoteur pour attraper un objet
{
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks)
  {
    grabbed = true;
    stop();
    gripperServo.write(120); //grab the object
    //delay(1000);
  }
  else
  {
    gripperServo.write(0); //Position de base du gripper (angle 0)
  }
}

void objectIsGrabbed(float distance)
//TODO, doit pouvoir reconnaitre qu'un objet est effectivement attrapé
{
  if (grabbed)
  {
    avoidObstacle(distance);
  }
}

/*float distanceBetweenRobotAndObject()
//Censée retourner la distance entre le robot et l'objet à attraper, en cm
{
}*/

void setup() 
{
  Serial.begin(9600);
  gripperServo.attach(gripperServoPin);
  rightWheel.attach(rightWheelPin);
  leftWheel.attach(leftWheelPin);
  pixy.init();
  gripperServo.write(0);
  HC12.begin(9600);
  //stop();
}

void loop() 
{
//  if(HC12.available()) {                         

//Serial.write(HC12.read());             

//} 

//if(Serial.available()){                  

  //HC12.write(12);   
  while (HC12.available()) {        // If HC-12 has data
    int val = HC12.read();
    Serial.println(HC12.read());      // Send the data to Serial monitor
  }
//}
  /*grabTheObject();
  distance = distanceSensor.ping_cm();
  avoidObstacle(distance);
  Serial.print("Distance : ");
  Serial.println(distance);
  fullSpeed();
  */
}