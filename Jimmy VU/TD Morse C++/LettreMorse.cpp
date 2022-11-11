#include "pins_arduino.h"
#include "LettreMorse.h"

const int interval = 1000;
unsigned long previousMillis = 0;

LettreMorse::LettreMorse()
{

}

LettreMorse::LettreMorse(char lettre)
{   
    this->lettre = lettre;
}


bool LettreMorse::tempsEstEcoule()
/// Permet de contrôler la durée de l'état HIGH/LOW de LED_BUILTIN ///
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) 
    {
        previousMillis = currentMillis;
        return true;
    }
    return false;
}

const char LettreMorse::getLettre()
{
    return this->lettre;
}
void LettreMorse::point()
{
    while(!tempsEstEcoule())
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
}

void LettreMorse::espacement()
{
    while(!tempsEstEcoule())
    { 
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void LettreMorse::tiret()
{
    for(int i =0; i < 3; ++i)
    {
        point();
    }
    
}

void LettreMorse::finDeLettre()
{
    int spaceBetweenWords = 3;
    for(int i = 0; i < spaceBetweenWords; i++)
    {
        espacement();
    }
}

void LettreMorse::clignoteLED()
{
    if(this->lettre == 'A')
    {
        lettreA();
    }

    if(this->lettre == 'B')
    {
        lettreB();
    }

    if(this->lettre == 'C')
    {
        lettreC();
    }

    if(this->lettre == 'D')
    {
        lettreD();
    }

    if(this->lettre == 'E')
    {
        lettreE();
    }

    if(this->lettre == 'F')
    {
        lettreF();

    }

    if(this->lettre == 'G')
    {
        lettreG();
    }

    if(this->lettre == 'H')
    {
        lettreH();

    }

    if(this->lettre == 'I')
    {
        lettreI();
    }

    if(this->lettre == 'J')
    {
        lettreJ();
    }

    if(this->lettre == 'K')
    {
        lettreK();

    }

    if(this->lettre == 'L')
    {
        lettreL();
    }

    if(this->lettre == 'M')
    {
        lettreM();
    }

    if(this->lettre == 'N')
    {
        lettreN();

    }

    if(this->lettre == 'O')
    {
        lettreO();
    }

    if(this->lettre == 'P')
    {
        lettreP();
    }

    if(this->lettre == 'Q')
    {
        lettreQ();

    }

    if(this->lettre == 'R')
    {
        lettreR();
    }

    if(this->lettre == 'S')
    {
        lettreS();
    }

    if(this->lettre == 'T')
    {
        lettreT();
    }

    if(this->lettre == 'U')
    {
        lettreU();
    }

    if(this->lettre == 'V')
    {
        lettreV();
    }

    if(this->lettre == 'W')
    {
        lettreW();

    }

    if(this->lettre == 'X')
    {
        lettreX();
    }

    if(this->lettre == 'Y')
    {
        lettreY();
    }

    if(this->lettre == 'Z')
    {
        lettreZ();
    }      
    
    Serial.print(this->lettre);
    finDeLettre();
}


void LettreMorse::lettreA()
{
    point(); 
    espacement(); 
    tiret();
}

void LettreMorse::lettreB()
{
    tiret();
    for(int i = 0; i < 3; ++i)
    {
        espacement();
        point();
    }
}

void LettreMorse::lettreC()
{
    tiret();
    espacement();
    point();

    espacement();

    tiret();
    espacement();
    point();

}

void LettreMorse::lettreD()
{
    tiret();
    for(int i = 0; i < 2; ++i)
    {
        espacement();
        point();
    }
}

void LettreMorse::lettreE()
{
    point();
}

void LettreMorse::lettreF()
{
    for(int i = 0; i < 2; ++i)
    {
        point();
        espacement();
    }
    tiret();
    espacement();
    point();
}

void LettreMorse::lettreG()
{
    for(int i = 0; i < 2; ++i)
    {
        tiret();
        espacement();
    }
    point();
}

void LettreMorse::lettreH()
{
    for(int i = 0; i < 3; ++i)
    {
        point();
        espacement();
    }
    point();
}


void LettreMorse::lettreI()
{
    point();
    espacement();
    point();
}

void LettreMorse::lettreJ()
{
    point();
    espacement();
    for(int i = 0; i < 2; ++i)
    {
        tiret();
        espacement();
    }
    tiret();
}

void LettreMorse::lettreK()
{
    tiret();
    espacement();
    point();
    espacement();
    tiret();
}

void LettreMorse::lettreL()
{
    point();
    espacement();
    tiret();
    for(int i = 0; i < 2; ++i)
    {
        espacement();
        point();
    }
}

void LettreMorse::lettreM()
{
    tiret();
    espacement();
    tiret();
}

void LettreMorse::lettreN()
{
    tiret();
    espacement();
    point();
}

void LettreMorse::lettreO()
{
    for(int i = 0; i < 2; ++i)
    {
        tiret();
        espacement();
    }
    tiret();
}

void LettreMorse::lettreP()
{
    point();
    espacement();
    tiret();
    espacement();
    tiret();
    espacement();
    point();
}

void LettreMorse::lettreQ()
{
    for(int i = 0; i < 2; ++i)
    {
        tiret();
        espacement();
    }
    point();
    espacement();
    tiret();
}

void LettreMorse::lettreR()
{
    point();
    espacement();
    tiret();
    espacement();
    point();
}

void LettreMorse::lettreS()
{
    for(int i = 0; i < 2; ++i)
    {
        point();
        espacement();
    }
    point();
}

void LettreMorse::lettreT()
{
    tiret();
}

void LettreMorse::lettreU()
{
    for(int i = 0; i < 2; ++i)
    {
        point();
        espacement();
    }
    tiret();
}

void LettreMorse::lettreV()
{
    for(int i = 0; i < 3; ++i)
    {
        point();
        espacement();
    }
    tiret();
}

void LettreMorse::lettreW()
{
    point();
    for(int i = 0; i < 2; ++i)
    {
        espacement();
        tiret();
    }
}

void LettreMorse::lettreX()
{
    tiret();
    espacement();
    for(int i = 0; i < 2; ++i)
    {
        point();
        espacement();
    }
    tiret();
}

void LettreMorse::lettreY()
{
    tiret();
    espacement();
    point();
    for(int i = 0; i < 2; ++i)
    {
        espacement();
        tiret();
    }
}

void LettreMorse::lettreZ()
{
    for(int i = 0; i < 2; ++i)
    {
        tiret();
        espacement();
    }
    point();
    espacement();
    point();
}