#include <Pixy2.h>
#include <SPI.h>
#include <Servo.h>

const int pin = 3;
const int pinRoue = 5;
Pixy2 pixy;
Servo servo;
Servo roue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(pin);
  roue.attach(pinRoue);
  roue.write(45);
  servo.write(0);
  pixy.init();
  pixy.setCameraBrightness(70);
}

void loop() {
  // put your main code here, to run repeatedly:
  testPixy();
  /*servo.write(0);
  delay(1000);
  servo.write(80);
  delay(1000);*/
}

void testPixy()
{
  pixy.ccc.getBlocks();
  if(pixy.ccc.numBlocks)
  {
    Serial.println(pixy.ccc.numBlocks);
    if(pixy.ccc.numBlocks>1)
    {
      servo.write(80);
    }
    else{
      servo.write(0);
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
  //delay(1000);
}
