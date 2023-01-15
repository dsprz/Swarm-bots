#include <Pixy2.h>
#include <SPI.h>
#include <Servo.h>

const int pin = 3;
const int leftWheelPin = 5;
const int rightWheelPin = 6;
Pixy2 pixy;
Servo servo;
Servo leftWheel;
Servo rightWheel;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(pin);
  leftWheel.attach(leftWheelPin);
  rightWheel.attach(rightWheelPin);
  //roue.write(45);
  servo.write(0);
  pixy.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //testPixy();
  rightWheel.write(0);
  leftWheel.write(180);
}

void testPixy()
{
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks)
  {
    Serial.println(pixy.ccc.numBlocks);
    if(pixy.ccc.numBlocks)
    {
      servo.write(120);
    }
    delay(1000);
    for(int i = 0; i < pixy.ccc.numBlocks; ++i)
    {
      Serial.print(" block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    }
  }
  else{
      servo.write(0);
    }
  //delay(1000);
}
