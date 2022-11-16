#include <Arduino.h>

class Traducteur {
    public :
        Traducteur();
        // les deux fonctions permettant de traduire :
        void traduitDelay(String mot);    // en utilisant delay
        void traduitMillis(String mot);   // en utilisant millis
    private : 
      const char court[2]="c";            //correspond à un temps court
      unsigned long currentTime=0;        //permet d'utiliser la fonction millis dans le Traducteur.cpp
      unsigned long previousTime=0;
      char charLettre;                    // utile dans le Traducteur.cpp pour pour transformer une lettre d'un tableau en char
      void allumerLedDelay(int duree);
      bool allumerLedMillis(int duree, bool ledState);
      bool AttendreMillis(int duree);
      String TabTraductlettres[28][2]={   //on met dans une matrice à deux colonnes la lettre de l'alphabet (colonne 1) et sa traduction en morse (colonne 2)
         {"a","cl"},
         {"b","lccc"},
         {"c","lclc"},
         {"d","lcc"},
         {"e","c"},
         {"f","cclc"},
         {"g","llc"},
         {"h","cccc"},
         {"i","cc"},
         {"j","clll"},
         {"k","lcl"},
         {"l","clcc"},
         {"m","ll"},
         {"n","lc"},
         {"o","lll"},
         {"p","cllc"},
         {"q","llcl"},
         {"r","clc"},
         {"s","ccc"},
         {"t","l"},
         {"u","ccl"},
         {"v","cccl"},
         {"w","cll"},
         {"x","lccl"},
         {"y","lcll"},
         {"z","llcc"},
         {" ",""},
         {"",""},     // on rajoute ce cas pour verrifier si ce n'est pas une lettre (utilisé dans le Traducteur.cpp)
         };
   };
 
 //+1
