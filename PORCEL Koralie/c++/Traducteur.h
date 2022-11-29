#include <Arduino.h>

class Traducteur {
    public :
      Traducteur();
      void traduitMot(String mot); // Fonction qui permet de traduire
    private : 
      void lettreTrouve(int i);
      bool attendre(bool ledState, int duree);
      const char court[2]="s";            //correspond à un temps short donc court
      unsigned long tempsActuel=0;        //permet d'utiliser la fonction millis dans le Traducteur.cpp
      unsigned long tempsAncien=0;
      String TabTraductlettres[37][2]={   //met dans une matrice à deux colonnes la lettre de l'alphabet (colonne 1) et sa traduction en morse (colonne 2)
         {"0","lllll"},
         {"1","sllll"},
         {"2","sslll"},
         {"3","sssll"},
         {"4","ssssl"},
         {"5","sssss"},
         {"6","lssss"},
         {"7","llsss"},
         {"8","lllss"},
         {"9","lllls"},
         {"a","sl"},
         {"b","lsss"},
         {"c","lsls"},
         {"d","lss"},
         {"e","s"},
         {"f","ssls"},
         {"g","lls"},
         {"h","ssss"},
         {"i","ss"},
         {"j","slll"},
         {"k","lsl"},
         {"l","slss"},
         {"m","ll"},
         {"n","ls"},
         {"o","lll"},
         {"p","slls"},
         {"q","llsl"},
         {"r","sls"},
         {"s","sss"},
         {"t","l"},
         {"u","ssl"},
         {"v","sssl"},
         {"w","sll"},
         {"x","lssl"},
         {"y","lsll"},
         {"z","llss"},
         {" ",""},
         };
   };
