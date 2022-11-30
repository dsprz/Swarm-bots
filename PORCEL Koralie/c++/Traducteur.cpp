#include "Traducteur.h"

Traducteur::Traducteur(){
  
}

//Permet de traduire une phrase
void Traducteur::traduitMot(String phrase){
    phrase.toLowerCase();                                    // met la phrase en minuscule
    tempsAncien=millis();                                    // on initialise le temps ancien à maintenant.
    for (int lettre=0;lettre<phrase.length();lettre++){      // pour toutes les lettres de la phrase à traduire   
      for (int i=0;i<37;i++){                                // pour toutes les lettres présente dans le tableau                                 
        char charLettre = TabTraductlettres[i][0].charAt(0); // récupère la lettre du tableau en un char
        if (phrase[lettre]==charLettre){                     // on regarde si la lettre du mot à traduire est égale au ième ocurance du tableau    
            lettreTrouve(i);
            break;                                           // on a trouvé la lettre, on peut sortir de la boucle
        }                                   
      }
    }    
}

//Permet de faire le cas lorsque la lettre est trouvée
void Traducteur::lettreTrouve(int i){
  if (i==36){ // si c'est un espace
      Serial.println("Nouveau mot");
      attendre(2400);     //on attend 2400ms car c'est un nouveau mot
  }
  else{
      Serial.print("Lettre ou chiffre : ");
      Serial.println(TabTraductlettres[i][0]);
      for(int k=0;k<TabTraductlettres[i][1].length();k++){  // pour tout caractère de la traduction morse (nombre de court et de long)
          if(TabTraductlettres[i][1][k]==court){            // on vérifie si la traduction de la lettre en morse est court ou long
              Serial.print("court ");
              clignotementLed(400);  // lors d'une impulsion court, la led reste allumée pendant 400ms
              }                        
          else{
              Serial.print("long ");
              clignotementLed(1200); // lors d'une impulsion longue, la led reste allumée pendant 1200ms
          }
      }
      Serial.println();  // va à la ligne
      attendre(1200);    // entre chaque lettre on laisse un peu plus de delai
  }
}


//Permet d'attendre
void Traducteur::attendre(int duree){
  tempsActuel=millis();
  while((tempsActuel-tempsAncien)<=duree){
    tempsActuel=millis();  
  }
  tempsAncien=tempsActuel;
}

//Allume la led pendant duree et éteint la led pendant 400ms
void Traducteur::clignotementLed(int duree){
  digitalWrite(LED_BUILTIN, true);  // on allume la led  
  attendre(duree);                  // on laisse la led allumée pendant duree
  digitalWrite(LED_BUILTIN, false); // on éteint la led
  attendre(400);                    // on laisse la led éteinte pendant 400ms    
}
