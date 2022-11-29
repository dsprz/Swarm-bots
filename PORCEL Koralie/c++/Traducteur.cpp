#include "Traducteur.h"

Traducteur::Traducteur(){
  
}

//Permet de traduire une phrase
void Traducteur::traduitMot(String phrase){
    phrase.toLowerCase();                                    // met le mot en minuscule
    tempsAncien=millis();                                    // on initialise le temps ancien à maintenant.
    for (int lettre=0;lettre<phrase.length();lettre++){      // pour toute les lettres dans la phrase à traduire   
      for (int i=0;i<37;i++){                                // pour toute les lettres présente dans le tableau                                 
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
      while (attendre(false,2400));     //on attend 2400 car c'est un nouveau mot, on laisse la led etteinte donc false (tant que la fonction renvoie vrai appele la fonction. Donc tant que 2400ms ne ce sont pas écoulée,l'appele)
  }
  else{
      Serial.print("Lettre ou chiffre : ");
      Serial.println(TabTraductlettres[i][0]);
      for(int k=0;k<TabTraductlettres[i][1].length();k++){  // pour tout carractère de la traduction morse (nombre de court et de long)
          if(TabTraductlettres[i][1][k]==court[0]){         // on verrifie si la traduction de la lettre en morse est court ou long
              Serial.print("court ");
              while (attendre(true, 400));               // on veut allumer la led (true) et la laisser 400ms allumée (400). Tant que le temps n'est pas écoulé(la fonction renvoie false), on rappele la fonction
              while (attendre(false,400));               // on veut etteindre la led (false) et on la laisse 400ms etteinte avant de continuer le programme 
              }                        
          else{
              Serial.print("long ");  
              while (attendre(true,1200));     // on veut allumer la led (true) et la laisser 400ms allumée (400). Tant que le temps n'est pas écoulé(ca n'a pas allumé la led), on rappele la fonction
              while (attendre(false,400));     // on veut etteindre la led (false) et on la laisse 400ms etteinte avant de continuer le programme 
          }
      }
      Serial.println();                // va à la ligne
      while (attendre(false,1200));    // entre chaque lettres on laisse un peu plus de delay, on laisse la led etteinte donc false
  }
}


//Permet d'attendre
bool Traducteur::attendre(bool ledState, int duree){
  tempsActuel=millis();
  digitalWrite(LED_BUILTIN, ledState);     // on allume ou on etteind la led
  if ((tempsActuel-tempsAncien)>=duree){   // si le temps actuel moins l'ancien temps est supérieur ou égal à la durée d'attente alors : 
     tempsAncien=tempsActuel;               
     return false;                         //condition d'arret de la boucle while quand on utilse cette fonction             
  }
  return true;
}
