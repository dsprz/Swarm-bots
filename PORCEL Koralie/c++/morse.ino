#include "Traducteur.h" 
Traducteur traducteur = Traducteur();
String motTraduire;
String delayOuMillis;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Quel mot voulez vous traduire en morse ? ");
  while(Serial.available() >0) {}       //ca permet de mettre en pause le terminal et d'attendre d'avoir une réponse pour le mettre dans motTraduire
  motTraduire = Serial.readString();
  delayOuMillis="";
  Serial.println("En utilisant delay (d) ou millis (m) ?");
  while(Serial.available() == 0) {}
  delayOuMillis = Serial.readString();
  while((delayOuMillis!="d") && (delayOuMillis!="m")){          // si la personne n'a pas répondu d ou m, rentre dans une boucle tant qu'ils écrivent pas l'un des deux
    Serial.println("Non, vous devez écrire 'd' pour delay ou 'm' pour millis");
    while(Serial.available() == 0) {}
    delayOuMillis = Serial.readString();
    }
  Serial.print("Le mot choisi est : ");
  Serial.println(motTraduire);
  if (delayOuMillis=="d"){
    traducteur.traduitDelay(motTraduire);
    }
  else{
    traducteur.traduitMillis(motTraduire);
    }
}
