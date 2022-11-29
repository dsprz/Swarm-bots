#include "Traducteur.h"

Traducteur::Traducteur()
{

}

void Traducteur::translateWord(String s)
// Traduit un mot en son équivalent morse 
{
    s.toUpperCase();
    setLettreMorseArray(s);

    for(int i = 0; i < s.length(); ++i)
    {
        this->word[i].blink();
    }
    Serial.println("");
}

void Traducteur::setLettreMorseArray(String s)
/* Initialise le tableau de LettreMorse
 * avec toutes les lettres de la phrase
 */ 
{
    int i = 0;
    for(const char &c : s)
    {
        this->word[i] = LettreMorse(c);
        i++;   
    }
}
