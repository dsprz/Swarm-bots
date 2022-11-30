/* Ecrit par Jimmy VU
 * Cette classe traduit une phrase
 * en morse. Les caractères non-alphanumériques
 * sont ignorés.
 */

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
