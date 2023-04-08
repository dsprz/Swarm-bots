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
const int x_center = pixy.frameWidth/2;
const int y_center = pixy.frameHeight/2;
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
  leftWheel.write(90);
}

void turnRight()
{
  rightWheel.write(90);
  leftWheel.write(180);
}

void turnLeft()
{
  rightWheel.write(0);
  leftWheel.write(90);
}

void goBackwards()
{
  rightWheel.write(135);
  leftWheel.write(0); 
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

uint16_t pixyGetHeight(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_height;
}

uint16_t pixyGetWidth(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_width;
}

uint16_t pixyGetX(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_x;
}

uint16_t pixyGetY(int block)
{
  pixy.ccc.getBlocks();
  return pixy.ccc.blocks[block].m_y;
}

void centerOnX(uint16_t current_x)
{
  const int x_margin = 10;
  const int y_margin = 2;
  if(current_x < 4*pixy.frameWidth/10 && current_x >= 0)
  {
    turnLeft();
    Serial.println("0-40");
  }

  if(current_x >= 4*pixy.frameWidth/10 && current_x < x_center - x_margin)
  {
      fullSpeed();
      Serial.println("40-centre");     
  }
    
  if(current_x >= x_center - x_margin && current_x <= x_center + x_margin)
  {
      fullSpeed();
      Serial.println("centre");
  }

  if(current_x > x_center + x_margin && current_x < 6*pixy.frameWidth/10)
  {
      fullSpeed();
      Serial.println("centre-60");
  }

  if(current_x >= 6*pixy.frameWidth/10 && current_x <=pixy.frameWidth)
  {
      turnRight(); 
      Serial.println("60-fin");
  }
}

void centerTheObject(int block)
{
  const int x_margin = 8;
  const int y_margin = 2;
  const int x_center = pixy.frameWidth/2;
  const int y_center = pixy.frameHeight/2;
  uint16_t current_x = pixyGetX(block);
  uint16_t current_y = pixyGetY(block);
  uint16_t objectHeight = pixyGetHeight(block);
  bool objectOutOfSight = current_x == 0 && current_y >= 400; //valeur arbitraire plus grande que frameheight
  float distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
  Serial.print("distance between object and robot = ");
  Serial.println(distanceBetweenObjectAndRobot);
  bool centered = false;

  while(distanceBetweenObjectAndRobot > knownDistance && !centered)
  {
    //On observe
      current_x = pixyGetX(block);
      current_y = pixyGetY(block);
      Serial.print("current X = ");
      Serial.println(current_x);
      Serial.print("current y = ");
      Serial.println(current_y);
      distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
      objectHeight = pixyGetHeight(block);

    centerOnX(current_x);
  //L'objet détecté est souvent au-dessus de y/2  
    /*if(current_y < y_center - y_margin/10 && !objectOutOfSight)
    {
      goBackwards();
      delay(1000);
      centerOnX(current_x);
      Serial.println("je recule et j'essaie de centrer sur x");
    }*/
    if(current_y >= y_center - y_margin && current_y <= y_center + y_margin)
    {
      centered = true;
      break;
    }

    if(distanceBetweenObjectAndRobot <= knownDistance && !centered)
    {
      Serial.print("Il manque ");
      Serial.print(x_center-x_margin-current_x);
      Serial.println(" pour etre centre x");
      goBackwards();
      delay(1500);
      centerOnX(current_x);      
    }
    if(objectOutOfSight)
    {
      fullSpeed();
      Serial.println("l'objet est OOS");
    }
    
    /*while (current_y < y_center - y_margin)
    {
      fullSpeed();
      Serial.print("current y = ");
      Serial.println(current_y);
      Serial.print("Center y axis = ");
      Serial.println(y_center-y_margin);
      current_y = pixyGetY(block);
      distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
      objectHeight = pixyGetHeight(block);
      Serial.print("object height = ");
      Serial.println(objectHeight);
    }  
    while (current_x > x_center + x_margin)
    {
      Serial.print("current X = ");
      Serial.println(current_x);
      Serial.println("droite");
      turnRight();
      current_x = pixyGetX(block);
      distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
      objectHeight = pixyGetHeight(block);
      Serial.print("object height = ");
      Serial.println(objectHeight);

    }
    while (current_x < x_center - x_margin)
    {
      Serial.print("current X = ");
      Serial.println(current_x);
      Serial.println("gauche");
      turnLeft();
      current_x = pixyGetX(block);   
      distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
      objectHeight = pixyGetHeight(block);
      Serial.print("object height = ");
      Serial.println(objectHeight);
    }
    Serial.print("distance between object and robot = ");
    Serial.println(distanceBetweenObjectAndRobot);
    Serial.print("known distance = ");
    Serial.println(knownDistance);
    Serial.println("j'ai bug");
  } 
   
  //Object has been centered
  stop();
  Serial.println("je stop");*/
  }
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
  gripperServo.attach(gripperServoPin);
  rightWheel.attach(rightWheelPin);
  leftWheel.attach(leftWheelPin);
  pixy.init();
  pixy.getResolution();
  gripperServo.write(30);
  HC12.begin(9600);
  stop();
}

void loop() 
{
  //fullSpeed();
  //grabTheObject();
  /*distance = distanceSensor.ping_cm();
  avoidObstacle(distance);*/
  int signature = 1;
  int block = pixyGetBlock(signature);
  /*uint16_t objectHeight = pixyGetHeight(block);
  Serial.print("object height = ");
  Serial.println(objectHeight);*/
  //float distanceBetweenObjectAndRobot = unknownDistance(objectHeight);
  //Serial.print(distanceBetweenObjectAndRobot); Serial.println("mm");
  //Serial.print("frameWidth : ");Serial.println(pixy.frameWidth/2);
  //Serial.print("frameHeight : ");Serial.println(pixy.frameHeight)
  pixyPrintBlockInfos();
  centerTheObject(block);

}