#ifndef _TRADUCTEUR_
#define _TRADUCTEUR_
#include "LettreMorse.h"


class Traducteur{
    public:
        Traducteur();
        void traduireMot(String s); 

    private:
        const static int longueurMax = 30;
        LettreMorse mot[longueurMax]; //Il fallait ajouter un constructeur LettreMorse avec 0 argument
        void setTableauLettreMorse(String s);
};

#endif