#include "Traducteur.h" 
Traducteur traducteur = Traducteur();  //crée un objet de la classe traducteur

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Quel phrase voulez vous traduire en morse ? ");
  while(Serial.available() == 0) {}       //ca permet de mettre en pause le terminal et d'attendre d'avoir une réponse pour le mettre dans motATraduire
  String motATraduire = Serial.readString();
  Serial.print("Vous avez choisi comme phrase : ");
  Serial.println(motATraduire);
  traducteur.traduitMot(motATraduire);
}
