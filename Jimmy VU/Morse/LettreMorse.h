/* Ecrit par Jimmy VU
 * Cette classe modélise une lettre
 * ou un chiffre en son équivalent morse
 */


#ifndef _LETTREMORSE_
#define _LETTREMORSE_
#include <Arduino.h>

class LettreMorse
{
    public:
        LettreMorse();
        LettreMorse(char letter);
        void blink();
        const char getLetter();

    private:
        unsigned long currentMillis;
        char letter;
        bool timeIsUp();
        void spacing();
        void spaceBetweenTwoWords();
        void dot();
        void dash();
        void endLetter();
        void letterA();
        void letterB();
        void letterC();
        void letterD();
        void letterE();
        void letterF();
        void letterG();
        void letterH();
        void letterI();
        void letterJ();
        void letterK();
        void letterL();
        void letterM();
        void letterN();
        void letterO();
        void letterP();
        void letterQ();
        void letterR();
        void letterS();
        void letterT();
        void letterU();
        void letterV();
        void letterW();
        void letterX();
        void letterY();
        void letterZ();
        void number0();
        void number1();
        void number2();
        void number3();
        void number4();
        void number5();
        void number6();
        void number7();
        void number8();
        void number9();
};

#endif
