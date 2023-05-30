#include "Communication.h"
const int RXD = 8;
const int TXD = 9;
SoftwareSerial HC(TXD, RXD);

Communication::Communication(char robotName)
{
  this->robotName = robotName;
}

void Communication::begin(int bps)
{
  HC.begin(bps);
}
//callRobot('K')
void Communication::callRobot(char robotName)
{
  HC.write(robotName);
}

//Attend un message
void Communication::receiveMessage()
{
    while(HC.available()) 
    {  
      char message = HC.read();
      Serial.print("message : "); Serial.println(message);
      this->called = message == this->robotName;
      this->confirmed = message == 'C';
      this->homePosition = message == 'H';
      this->abort = message == 'A';
    }
}
void Communication::callMiniBot(char robotName)
{
  while(!this->called)
  {
    Serial.println("calling K");
    this->callRobot(robotName);
    delay(delayTime);
    this->receiveMessage();
  }
}

void Communication::waitForHomePosition()
{
  while(!this->homePosition)
  {
    this->receiveMessage();
  }
}

//baton de colle c'est 1, cylindre bleu c'est 2
void Communication::sendObjectToGrab(int signature)
{
  int ASCII = 48+signature;   
  char ASCIISignature = ASCII;
  while(!this->confirmed)
  {
    Serial.println("sending1");
    HC.write(ASCIISignature);
    delay(delayTime);
    this->receiveMessage();
  }
}

bool Communication::getHomePosition()
{
  return this->homePosition;  
}

bool Communication::getAbort()
{
  return this->abort;
}

void Communication::setCalled(bool called)
{
  this->called = called;
}

void Communication::setHomePosition(bool homePosition)
{
  this->homePosition = homePosition;
}

void Communication::setConfirmed(bool confirmed)
{
  this->confirmed = confirmed;
}

void Communication::resetAllBooleans()
{
  this->setCalled(false);
  this->setConfirmed(false);
  this->setHomePosition(false);
  this->abort = false;
}