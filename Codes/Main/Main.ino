#include <Pixy2.h>
#include <Servo.h>
#include <NewPing.h>
#include <SoftwareSerial.h>
#include <string.h>

const int gripperServoPin = 3;
const int leftWheelPin = 5;
const int rightWheelPin = 6;
const int HC12_RXD = 8;
const int HC12_TXD = 9;
const int trigger = 14;
const int echo = 15;
const int maxDistance = 350; //cm
const char robotName = 'K';
bool called = false;
bool signatureCalled = false;
char possibleSignatures[8] = {'1', '2', '3', '4', '5', '6', '7'};

//Valeurs connues por calculer la distance focale de la Pixy
float knownObjectHeight = 80 ; //mm
float pixelHeight = 123; //px
float knownDistance = 125; //mm
float focalDistance = pixelHeight*knownDistance/knownObjectHeight;
float distance; //mm

bool grabbing = false; //Pour l'instant ces deux bools ne servent à rien
bool grabbed = false;
//ASCII 49 = 1

Pixy2 pixy;
//int8_t x_center = pixy.getResolution();
int y_center = pixy.frameHeight/2;
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
int pixyGetBlock(int signature)
{
    pixy.ccc.getBlocks();

    for(int i = 0; i < pixy.ccc.numBlocks; ++i)
    {
      if (pixy.ccc.blocks[i].m_signature == signature)
      {
        return i;
      }
    } 
}

int pixyGetHeight(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_height;
}

int pixyGetWidth(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_width;
}

int pixyGetX(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_x;
}

int pixyGetY(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_y;
}
int centerTheObject(int block)
{
  const int x_margin = 1;
  const int y_margin = 1;
  const int x_center = pixy.frameWidth/2;
  const int y_center = pixy.frameHeight/2;
  int current_x = pixyGetX(block);
  int current_y = pixyGetY(block);
  while (current_y < y_center - y_margin)
  {
    fullSpeed();
  }  
  while (current_x > x_center + x_margin)
  {
    turnLeft();
  }
  while (current_x < x_center - x_margin)
  {
    turnRight();
  }
  //Object has been centered
  stop();
}

float unknownDistance(int pixyHeight)
{
  return focalDistance*knownObjectHeight/pixyHeight;
}
void pixyPrintBlockInfos()
//Affiche les informations utiles de la Pixy pour la détection d'objets

{
    pixy.ccc.getBlocks();

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
    gripperServo.write(30); //Position de base du gripper (angle 0)
  }
}

void callRobot(char message)
{
  HC12.write(message);
}

void sendObjectToGrab(int signature)
{
  int ASCII = 48+signature;   
  char ASCIISignature = ASCII;    
  HC12.write(ASCIISignature);
}

char receiveMessage()
{                  
    while (HC12.available()) 
    {  
      char message = HC12.read();
      Serial.print("message : "); Serial.println(message);
      if (message == robotName)
      {
        called = true;
        return message;
      }
      else
      {
        for(char &c : possibleSignatures)
        {
          //Serial.println(c);
          delay(100);

          if(message == c)
          {
            signatureCalled = true;
            return message;
          }        
        }
      }

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
  /*gripperServo.attach(gripperServoPin);
  rightWheel.attach(rightWheelPin);
  leftWheel.attach(leftWheelPin);
  pixy.init();
  pixy.getResolution();
  gripperServo.write(30);*/
  HC12.begin(9600);
  //stop();
}

void loop() 
{

//  if(HC12.available()) {                         

//Serial.write(HC12.read());             

//} 

//if(Serial.available()){                  

  /*HC12.write(12);   
  while (HC12.available()) {        // If HC-12 has data
    int val = HC12.read();
    Serial.println(HC12.read());      // Send the data to Serial monitor
  }
//}*/
  /*grabTheObject();
  distance = distanceSensor.ping_cm();
  avoidObstacle(distance);
  Serial.print("Distance : ");
  Serial.println(distance);
  fullSpeed();*/
  //pixyPrintBlockInfos();
  /*int objectHeight = pixyGetHeight(0);
  distance = unknownDistance(objectHeight);
  Serial.print(distance); Serial.println("mm");
  delay(1000); */
  //Serial.print("frameWidth : ");Serial.println(pixy.frameWidth);
  //Serial.print("frameHeight : ");Serial.println(pixy.frameHeight);


  //Spider
  /*while(!called)
  {
    callRobot('K');
    Serial.println("callingK");
    receiveMessage();
  }
  while(called)
  {
    Serial.println("sending1");
    sendObjectToGrab(1);    
  }
  //EndSpider
  */
  //Bot
  while(!called)
  {
    receiveMessage();
    Serial.println("lol");
  }
  while(!signatureCalled)
  {
    callRobot('S'); //oui ?
    Serial.println("CALLING S");    
    receiveMessage();
  } 
  Serial.println("kekw"); 
  char signature = receiveMessage();
  Serial.println(signature);

    //pixyGetBlock(signature);
  /*if (called)
  {
    pixyGetBlock();    
  }*/

}