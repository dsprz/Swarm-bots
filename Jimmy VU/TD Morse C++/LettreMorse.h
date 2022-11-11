#ifndef _LETTREMORSE_
#define _LETTREMORSE_
#include <Arduino.h>

class LettreMorse
{

    public:
        LettreMorse();
        LettreMorse(char lettre);
        void clignoteLED();
        const char getLettre();

    private:
        char lettre;
        bool tempsEstEcoule();
        void espacement();
        void point();
        void tiret();
        void finDeLettre();
        void lettreA();
        void lettreB();
        void lettreC();
        void lettreD();
        void lettreE();
        void lettreF();
        void lettreG();
        void lettreH();
        void lettreI();
        void lettreJ();
        void lettreK();
        void lettreL();
        void lettreM();
        void lettreN();
        void lettreO();
        void lettreP();
        void lettreQ();
        void lettreR();
        void lettreS();
        void lettreT();
        void lettreU();
        void lettreV();
        void lettreW();
        void lettreX();
        void lettreY();
        void lettreZ();

};

#endif
