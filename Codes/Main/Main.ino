#include <Pixy2.h>
#include <Servo.h>
#include <NewPing.h>

const int gripperServoPin = 3;
const int leftWheelPin = 5;
const int rightWheelPin = 6;
const int trigger = 14;
const int echo = 15;
const int maxDistance = 350; //cm
//float stickGlueHeight = 6 ; //cm
float distance;
bool grabbing = false;
bool grabbed = false;

Pixy2 pixy;
Servo gripperServo;
Servo rightWheel;
Servo leftWheel;
NewPing distanceSensor(trigger, echo, maxDistance);

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
//Le robot tourne à droite pour éviter un obstable
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
    gripperServo.write(0); //gripper base position (no object)
  }
}

void objectIsGrabbed(float distance)
//A remplacer, doit pouvoir reconnaitre qu'un objet est effectivement attrapé
{
  if (grabbed)
  {
    avoidObstacle(distance);
  }
}

/*float distanceBetweenRobotAndObject()
//Censée retourner la distance entre le robot et l'objet à attraper, en cm
{
  distanceHeight = 3;
}*/

void setup() 
{
  Serial.begin(9600);
  //pinMode(trigger, OUTPUT);
  //pinMode(echo, INPUT);
  gripperServo.attach(gripperServoPin);
  rightWheel.attach(rightWheelPin);
  leftWheel.attach(leftWheelPin);
  pixy.init();
  gripperServo.write(0);
  //stop();
}

void loop() 
{
  /*grabTheObject();
  distance = distanceSensor.ping_cm();
  avoidObstacle(distance);
  Serial.print("Distance : ");
  Serial.println(distance);*/
  //rightWheel.write(0);
  //fullSpeed();
  //rightWheel.write(0);
}