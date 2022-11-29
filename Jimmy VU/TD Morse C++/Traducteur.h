#ifndef _TRADUCTEUR_
#define _TRADUCTEUR_
#include "LettreMorse.h"


class Traducteur{
    public:
        Traducteur();
        void translateWord(String word);

    private:
        const static int maxLength = 250;
        LettreMorse word[maxLength]; 
        void setLettreMorseArray(String s);
};

#endif
