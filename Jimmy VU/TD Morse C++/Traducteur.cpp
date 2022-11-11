#include "HardwareSerial.h"
#include "Traducteur.h"

Traducteur::Traducteur()
{

}

void Traducteur::traduireMot(String s)
{
    s.toUpperCase();
    setTableauLettreMorse(s);

    for(int i = 0; i < s.length(); ++i)
    {
        this->mot[i].clignoteLED();
    }
    Serial.println("");
}

void Traducteur::setTableauLettreMorse(String s)
/// Initialise le tableau LettreMorse ///
{
    int i = 0;
    for(const char &c : s)
    {
        this->mot[i] = LettreMorse(c);
        i++;   
    }
}