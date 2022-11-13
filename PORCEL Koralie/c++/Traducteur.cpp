#include "Traducteur.h"

Traducteur::Traducteur(){
  
}

void Traducteur::traduitDelay(String mot){
    mot.toLowerCase();                                        // transforme le mot en minuscule
    for (int lettre=0;lettre<mot.length();lettre++){          // pour toute les lettres dans le mot à traduire 
      for (int i=0;i<=27;i++){                                // taille du tableau lettres, on verrifie pour toute les lettres  
        charLettre = TabTraductlettres[i][0].charAt(0);       // récupère la lettre en char
        if (mot[lettre]==charLettre){                         // on regarde si la lettre du mot à traduire est égale au ième ocurance du tableau
          if (i==26){                                         // si c'est un espace
            Serial.println("Nouveau mot");
            delay(2400);                                      // entre chaques mots, il y a une plus longue attente
            }
          else{
            Serial.print("Lettre : ");
            Serial.println(TabTraductlettres[i][0]);
            for(int k=0;k<TabTraductlettres[i][1].length();k++){// pour tout carractère de la traduction morse (nombre de court et de long)
              if(TabTraductlettres[i][1][k]==court[0]){         // on verrifie si la traduction de la lettre en morse est court ou long
                Serial.print("court ");
                allumerLedDelay(400);                           // si c'est court alors la led reste 400ms allumée
                }
              else{
                Serial.print("long ");  
                allumerLedDelay(1200);                          // si c'est long alors la led reste 1200ms allumée
              }
            }
            Serial.println();                                   // va à la ligne
            delay(1200);                                        // entre chaque lettres on laisse un peu plus de delay
          }
          break;                                                // on sort de la boucle car on a trouvé la bonne lettre
        }
        else if (i==27){                                        //cas ou ce n'est pas une lettre : on arrive à la fin du tableau et aucune lettre n'a été trouvée ( tableau à 27 caractères)
           Serial.print(mot[lettre]);
           Serial.println(" : ce n'est pas une lettre");
        }                                   
      }
    }
    delay(1200);    //on attend car c'est la fin du mot. Or entre chaque mot il y a 2400ms et il y a forcément (sauf si le mot est vide mais ducoup on a pas besoin d'attendre) au moins 1200ms d'attente deja(led etteinte apres une lettre 1200ms ou après un espace 2400ms d'attente)     
}
void Traducteur::allumerLedDelay(int duree){
  digitalWrite(LED_BUILTIN, HIGH);  // on allume la led
  delay(duree);
  digitalWrite(LED_BUILTIN, LOW);   // on etteint la led
  delay(400);
  }               

void Traducteur::traduitMillis(String mot){
    mot.toLowerCase();                                        // transforme le mot en minuscule
    for (int lettre=0;lettre<mot.length();lettre++){          // pour toute les lettres dans le mot à traduire 
      for (int i=0;i<=27;i++){                                // taille du tableau lettres, on verrifie pour toute les lettres  
        charLettre = TabTraductlettres[i][0].charAt(0);       // récupère la lettre en char
        if (mot[lettre]==charLettre){                         // on regarde si la lettre du mot à traduire est égale au ième ocurance du tableau
          if (i==26){                                         // si c'est un espace
            Serial.println("Nouveau mot");
            allumerLedMillis(2400,false);                     // entre chaque mot, on laisse un peu de delay. Ici, la led est étteinte(false) et le delay est de 2400ms                    
            }
          else{
            Serial.print("Lettre : ");
            Serial.println(TabTraductlettres[i][0]);
            for(int k=0;k<TabTraductlettres[i][1].length();k++){// pour tout carractère de la traduction morse (nombre de court et de long)
              if(TabTraductlettres[i][1][k]==court[0]){         // on verrifie si la traduction de la lettre en morse est court ou long
                Serial.print("court ");
                while (!allumerLedMillis(400, true));           // on veut allumer la led (true) et la laisser 400ms allumée (400). Tant que le temps n'est pas écoulé(ca n'a pas allumé la led), on rappele la fonction
                }
              else{
                Serial.print("long ");  
                while (!allumerLedMillis(1200, true));          // on veut allumer la led (true) et la laisser 1200ms allumée (400) 
              }
            }
            Serial.println();    
            allumerLedMillis(1200,false);                       // entre chaque lettres on laisse un peu plus de delay
          }
          break;                                                // on sort de la boucle car on a trouvé la bonne lettre
        }
        else if (i==27){                                        //cas ou ce n'est pas une lettre : on arrive à la fin du tableau et aucune lettre n'a été trouvée ( tableau à 27 caractères)
         Serial.print(mot[lettre]);
         Serial.println(" : ce n'est pas une lettre");
        }                                     
      }
    }
    allumerLedMillis(1200,false); //on attend car c'est la fin du mot. Or entre chaque mot il y a 2400ms et il y a forcément (sauf si le mot est vide mais ducoup on a pas besoin d'attendre) au moins 1200ms d'attente deja(led etteinte apres une lettre ou après un espace 2400ms d'attente)
}


bool Traducteur::allumerLedMillis(int duree, bool ledState){
  currentTime=millis();
  if ((currentTime-previousTime)>duree){   // si le temps actuel - l'ancien temps est supérieur à duree alors : 
    previousTime=currentTime;               
    digitalWrite(LED_BUILTIN, ledState);   // on allume ou on etteind la led
    return true;                  
  }
  return false;
}
