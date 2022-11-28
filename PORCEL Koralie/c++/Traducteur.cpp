#include "Traducteur.h"

Traducteur::Traducteur(){
  
}

//Permet de traduire une phrase
void Traducteur::traduitMot(String phrase){
    phrase.toLowerCase();                                    // met le mot en minuscule
    previousTime=millis();                                   // on initialise le temps ancien à maintenant.
    for (int lettre=0;lettre<phrase.length();lettre++){      // pour toute les lettres dans la phrase à traduire   
      for (int i=0;i<37;i++){                                // pour toute les lettres présente dans le tableau                                 
        char charLettre = TabTraductlettres[i][0].charAt(0); // récupère la lettre en char
        if (phrase[lettre]==charLettre){                     // on regarde si la lettre du mot à traduire est égale au ième ocurance du tableau    
            lettreTrouve(i);
        }                                   
      }
    }    
}

//Permet de faire le cas lorsque la lettre est trouvée
void Traducteur::lettreTrouve(int i){
  if (i==36){ // si c'est un espace
      Serial.println("Nouveau mot");
      while (attendre(2400));     //on attend 2400 car c'est un nouveau mot (tant que la fonction renvoie vrai, l'appel donc tant que 2400ms ne ce sont pas écoulée,l'appel)
  }
  else{
      Serial.print("Lettre : ");
      Serial.println(TabTraductlettres[i][0]);
      for(int k=0;k<TabTraductlettres[i][1].length();k++){  // pour tout carractère de la traduction morse (nombre de court et de long)
          if(TabTraductlettres[i][1][k]==court[0]){         // on verrifie si la traduction de la lettre en morse est court ou long
              Serial.print("court ");
              while (allumerLed(true, 400));               // on veut allumer la led (true) et la laisser 400ms allumée (400). Tant que le temps n'est pas écoulé(la fonction renvoie false), on rappele la fonction
              while (allumerLed(false,400));               // on veut etteindre la led (false) et on la laisse 400ms etteinte avant de continuer le programme 
              }                        
          else{
              Serial.print("long ");  
              while (allumerLed(true,1200));     // on veut allumer la led (true) et la laisser 400ms allumée (400). Tant que le temps n'est pas écoulé(ca n'a pas allumé la led), on rappele la fonction
              while (allumerLed(false,400));     // on veut etteindre la led (false) et on la laisse 400ms etteinte avant de continuer le programme 
          }
      }
      Serial.println();          // va à la ligne
      while (attendre(1200));   // entre chaque lettres on laisse un peu plus de delay
  }
}


//Permet d'attendre
bool Traducteur::attendre(int duree){
  currentTime=millis();
  if ((currentTime-previousTime)>=duree){   // si le temps actuel moins l'ancien temps est supérieur ou égal à la durée d'attente alors : 
    previousTime=currentTime;               
    return false;                           //condition d'arret de la boucle while quand on utilse cette fonction             
  }
  return true;
}

//Permet d'allumer une led           
bool Traducteur::allumerLed(bool ledState, int duree){
  currentTime=millis();
  digitalWrite(LED_BUILTIN, ledState);      // on allume ou on etteind la led
  if ((currentTime-previousTime)>=duree){   // si le temps actuel moins l'ancien temps est supérieur ou égal à la durée d'attente alors :
    previousTime=currentTime;                 
    return false;                           //condition d'arret de la boucle while quand on utilse cette fonction
  }
  return true;
}
