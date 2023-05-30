#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <Arduino.h>
#include <SoftwareSerial.h>

class Communication
{
    public:
      Communication(char robotName);
      void discussion();
      char getSignature();
      void begin(int bps);
      void callMiniBot(char robotName);
      void sendObjectToGrab(int signature);
      void waitForHomePosition();
      bool getHomePosition();
      bool getAbort();
      void resetAllBooleans();
      void receiveMessage();

    private:
      const int delayTime = 500;
      char robotName;
      char signature;
      bool called = false;
      bool confirmed = false;
      bool homePosition = false;
      bool abort = false;
      char possibleSignatures[8] = {'1', '2', '3', '4', '5', '6', '7'};
      void callRobot(char robotName);
      void setCalled(bool called);
      void setConfirmed(bool confirmed);
      void setHomePosition(bool homePosition);
};
#endif