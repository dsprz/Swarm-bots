#include "Moving.h"
Moving moving = Moving();

void setup() {
  Serial.begin(9600);
  moving.initialisation();
}

void loop() {
  moving.avancer();
}
