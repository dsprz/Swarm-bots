#include <Arduino.h>
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.1.1
TFLI2C tflI2C;
#include <NewPing.h>
#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 250 // Maximum distance we want to ping for (in centimeters).
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Use this default I2C address
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);  // Initalize serial port
    Wire.begin();           // Initalize Wire library

}
 
void loop(){
  while (capteurIR()<100 or (capteurUltrason()<100 && capteurUltrason()>1)){
    digitalWrite(LED_BUILTIN, false); 
  } // rester dans cette boucle tant que <10cm
  digitalWrite(LED_BUILTIN, true);  // on allume la led 
  delay(200);
    
}
  


long capteurUltrason(){
  delay(29);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.println("UltraSon : "+String(sonar.convert_cm(uS))+" cm"); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  return(sonar.convert_cm(uS));
}

int16_t capteurIR(){
  if(tflI2C.getData(tfDist, tfAddr)){
     Serial.println("IR : "+String(tfDist)+" cm");
     return(tfDist);
  }
}
