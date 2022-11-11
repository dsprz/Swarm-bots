#include "LettreMorse.h"
#include "Traducteur.h"

Traducteur traducteur = Traducteur();


void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    //traducteur.traduireMot("tree");
    //traducteur.traduireMot("DOG");
    while(Serial.available() == 0)
    {
    }
    String mot = Serial.readString();
    mot.trim();
    traducteur.traduireMot(mot);

}

