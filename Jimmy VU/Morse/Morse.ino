#include "LettreMorse.h"
#include "Traducteur.h"

Traducteur translator = Traducteur();

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    //translator.translateWord("Ecrivez une phrase ici");
    translator.translateWord("é'A,RbR@e!;");
}
