/* Ecrit par Jimmy VU
 * Normalement, le code fonctionne pour au moins Arduino 1.8.x.
 * Pour vos tests, vous pouvez modifier le temps 
 * durant lequel LED_BUILTIN est allumée/éteinte
 * en allant dans LettreMorse.cpp et en modifiant
 * la variable const int interval qui se trouve
 * en tête du fichier. Par défaut elle vaut 1000.
 */

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
    /*Utilisez translator.translateWord(string) pour traduire une phrase.
     *translator.translateWord("Ecrivez une phrase ici");
     */
    translator.translateWord("é'A,RbR@e!;");
}
