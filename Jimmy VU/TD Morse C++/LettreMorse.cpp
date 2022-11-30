#include "pins_arduino.h"
#include "LettreMorse.h"

const int interval = 1000;            /* Intervalle modifiable durant lequel 
                                      * LED_BUILTIN est allumé ou éteint
                                      */

unsigned long previousMillis = 0;

LettreMorse::LettreMorse()
{

}

LettreMorse::LettreMorse(char letter)
{   
    this->letter = letter;
}

bool LettreMorse::timeIsUp()
// Permet de contrôler la durée de l'état HIGH/LOW de LED_BUILTIN 
{
    this->currentMillis = millis();
    if (this->currentMillis - previousMillis >= interval) 
    {
        previousMillis = this->currentMillis;
        return true;
    }
    return false;
}

// Les fonctions suivantes font clignoter LED_BUILTIN en morse

void LettreMorse::dot()
{
    while(!timeIsUp())
    {
        //Serial.println("dot");
        digitalWrite(LED_BUILTIN, HIGH);
    }
}

void LettreMorse::spacing()
{
    while(!timeIsUp())
    {   
       // Serial.println("spacing");
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void LettreMorse::dash()
{
    for(int i = 0; i < 3; ++i)
    {
        while(!timeIsUp())
        {
         // Serial.println("dash");
            digitalWrite(LED_BUILTIN, HIGH);
        }    
    }
    
}

const char LettreMorse::getLetter()
{
    return this->letter;
}

void LettreMorse::blink()
/* Fait clignoter LED_BUILTIN en morse 
 * en fonction de la lettre ou du chiffre.
 * Ignore les caractères non-alphanumériques (accents compris)
 * sauf 'Espace'.
 */
{
    switch(this->letter)
    {
        case 'A':
            letterA();
            break;
        case 'B':
            letterB();
            break;
        case 'C':
            letterC();
            break;
        case 'D':
            letterD();
            break;
        case 'E':
            letterE();
            break;
        case 'F':
            letterF();
            break;
        case 'G':
            letterG();
            break;
        case 'H':
            letterH();
            break;
        case 'I':
            letterI();
            break;
        case 'J':
            letterJ();
            break;
        case 'K':
            letterK();
            break;
        case 'L':
            letterL();
            break;
        case 'M':
            letterM();
            break;
        case 'N':
            letterN();
            break;
        case 'O':
            letterO();
            break;
        case 'P':
            letterP();
            break;
        case 'Q':
            letterQ();
            break;
        case 'R':
            letterR();
            break;
        case 'S':
            letterS();
            break;
        case 'T':
            letterT();
            break;
        case 'U':
            letterU();
            break;
        case 'V':
            letterV();
            break;
        case 'W':
            letterW();
            break;
        case 'X':
            letterX();
            break;
        case 'Y':
            letterY();
            break;
        case 'Z':
            letterZ();
            break;
        case ' ':
            spaceBetweenTwoWords();
            break;
        case '0':
            number0();
            break;
        case '1':
            number1();
            break;
        case '2':
            number2();
            break;
        case '3':
            number3();
            break;
        case '4':
            number4();
            break;
        case '5':
            number5();
            break;
        case '6':
            number6();
            break;
        case '7':
            number7();
            break;
        case '8':
            number8();
            break;
        case '9':
            number9();
            break;
        default:
            return;
    }
    endLetter();
    Serial.print(this->letter);
}


/* Les fonctions qui suivent traduisent
 * une lettre (et 'Espace') ou un chiffre en morse
 */

void LettreMorse::letterA()
{
    dot();
    spacing(); 
    dash();
}

void LettreMorse::letterB()
{
    dash();
    for(int i = 0; i < 3; ++i)
    {
        spacing();
        dot();
    }
}

void LettreMorse::letterC()
{
    dash();
    spacing();
    dot();

    spacing();

    dash();
    spacing();
    dot();

}

void LettreMorse::letterD()
{
    dash();
    for(int i = 0; i < 2; ++i)
    {
        spacing();
        dot();
    }
}

void LettreMorse::letterE()
{
    dot();
}

void LettreMorse::letterF()
{
    for(int i = 0; i < 2; ++i)
    {
        dot();
        spacing();
    }
    dash();
    spacing();
    dot();
}

void LettreMorse::letterG()
{
    for(int i = 0; i < 2; ++i)
    {
        dash();
        spacing();
    }
    dot();
}

void LettreMorse::letterH()
{
    for(int i = 0; i < 3; ++i)
    {
        dot();
        spacing();
    }
    dot();
}


void LettreMorse::letterI()
{
    dot();
    spacing();
    dot();
}

void LettreMorse::letterJ()
{
    dot();
    spacing();
    for(int i = 0; i < 2; ++i)
    {
        dash();
        spacing();
    }
    dash();
}

void LettreMorse::letterK()
{
    dash();
    spacing();
    dot();
    spacing();
    dash();
}

void LettreMorse::letterL()
{
    dot();
    spacing();
    dash();
    for(int i = 0; i < 2; ++i)
    {
        spacing();
        dot();
    }
}

void LettreMorse::letterM()
{
    dash();
    spacing();
    dash();
}

void LettreMorse::letterN()
{
    dash();
    spacing();
    dot();
}

void LettreMorse::letterO()
{
    for(int i = 0; i < 2; ++i)
    {
        dash();
        spacing();
    }
    dash();
}

void LettreMorse::letterP()
{
    dot();
    spacing();
    dash();
    spacing();
    dash();
    spacing();
    dot();
}

void LettreMorse::letterQ()
{
    for(int i = 0; i < 2; ++i)
    {
        dash();
        spacing();
    }
    dot();
    spacing();
    dash();
}

void LettreMorse::letterR()
{
    dot();
    spacing();
    dash();
    spacing();
    dot();
}

void LettreMorse::letterS()
{
    for(int i = 0; i < 2; ++i)
    {
        dot();
        spacing();
    }
    dot();
}

void LettreMorse::letterT()
{
    dash();
}

void LettreMorse::letterU()
{
    for(int i = 0; i < 2; ++i)
    {
        dot();
        spacing();
    }
    dash();
}

void LettreMorse::letterV()
{
    for(int i = 0; i < 3; ++i)
    {
        dot();
        spacing();
    }
    dash();
}

void LettreMorse::letterW()
{
    dot();
    for(int i = 0; i < 2; ++i)
    {
        spacing();
        dash();
    }
}

void LettreMorse::letterX()
{
    dash();
    spacing();
    for(int i = 0; i < 2; ++i)
    {
        dot();
        spacing();
    }
    dash();
}

void LettreMorse::letterY()
{
    dash();
    spacing();
    dot();
    for(int i = 0; i < 2; ++i)
    {
        spacing();
        dash();
    }
}

void LettreMorse::letterZ()
{
    for(int i = 0; i < 2; ++i)
    {
        dash();
        spacing();
    }
    dot();
    spacing();
    dot();
}

void LettreMorse::number0()
{
  for(int i = 0; i < 4; ++i)
  {
    dash();
    spacing();
  }
  dash();
}

void LettreMorse::number1()
{
  dot();
  spacing();
  for(int i = 0; i < 3; ++i)
  {
    dash();
    spacing();
  }
  dash();
}

void LettreMorse::number2()
{
  for(int i = 0; i < 2; ++i)
  {
    dot();
    spacing();
  }
  for(int i = 0; i < 2; ++i)
  {
    dash();
    spacing();
  }
  dash();
}

void LettreMorse::number3()
{
  for(int i = 0; i < 3; ++i)
  {
    dot();
    spacing();
  }
  dash();
  spacing();
  dash();
}

void LettreMorse::number4()
{
  for(int i = 0; i < 4; ++i)
  {
    dot();
    spacing();
  }
  dash();
}

void LettreMorse::number5()
{
  for(int i = 0; i < 4; ++i)
  {
    dot();
    spacing();
  }
  dot();
}

void LettreMorse::number6()
{
  dash();
  spacing();
  for(int i = 0; i < 3; ++i)
  {
    dot();
    spacing();
  }
  dot();
}

void LettreMorse::number7()
{
  for(int i = 0; i < 2; ++i)
  {
    dash();
    spacing();
  }
  for(int i = 0; i < 2; ++i)
  {
    dot();
    spacing();
  }
  dot();
}

void LettreMorse::number8()
{
  for(int i = 0; i < 3; ++i)
  {
    dash();
    spacing();
  }
  dot();
  spacing();
  dot();
}

void LettreMorse::number9()
{
  for(int i = 0; i < 4; ++i)
  {
    dash();
    spacing();
  }
  dot();
}

void LettreMorse::endLetter()
/* Sépare les lettres entre elles
 * en ajoutant un espace
 */
{
    const int spaceBetweenLetters = 3;
    for(int i = 0; i < spaceBetweenLetters; i++)
    {
        while(!timeIsUp())
        {
            // Serial.println("Fin De Lettre");
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}

void LettreMorse::spaceBetweenTwoWords()
/* Sépare les mots entre eux
 * en ajoutant un espace plus long
 */ 
{
  const int spaceBetweenWords = 7;
  for(int i = 0; i < spaceBetweenWords; ++i)
    {
        while(!timeIsUp())
        {
            // Serial.println("Espace entre deux mots");
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
