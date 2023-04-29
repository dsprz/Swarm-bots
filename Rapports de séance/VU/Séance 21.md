Séance 21

J'ai soudé 2 nouveaux émetteurs. Koralie m'a dit de faire des fils plus longs pour son araignée.

Pour le cable management, je devais trouver un moyen de faire une ligne de + et une ligne de -.
J'ai commencé en utilisant la breadboard, sauf qu'après avoir fait tous les branchements, j'ai eu un problème de poids et surtout de place.
J'ai alors décidé de chercher une autre solution : j'ai pris un connecteur avec des pins, j'ai dénudé un fil de cuivre et j'ai soudé la partie dénudée aux pins.
Grâce à ça, les pins sont tous connectés entre eux et je peux avoir une ligne de + puis une ligne de -. Ces lignes prennent très peu de place en plus d'avoir un poids très négligeable par rapport à la breadboard.

J'ai eu un problème lorsque j'ai testé les récepteurs. Je branche mon récepteur au pin A0, je lance un code très simple qui me permet d'afficher la tension analogique dans le serial monitor.
Lorsque je le lance isolé du code main, ça fonctionne très bien. Par contre dès que je la mettais dans le main, le serial monitor m'affichait toujours 0. J'ai trouvé d'où venait le problème : j'avais déclaré int pinA0 = A0 et plus loin int triggerPin = 15. En fait triggerPin était initialement conçu pour un HC-SR 04 parce que la Pixy "gênait" les pins digitaux de 0 à 14 et puisque j'ai déclaré le pin 15 comme un pin digital, le résultat sur le sérial monitor allait forcément être 0 ou 1 (en l'occurrence 0 ici). Du coup j'ai changé le pin sur 17 et tout marche correctement.

Je pense avoir cassé le VIN d'une de mes Arduinos : je lui ai mis 6V puis 7V mais elle n'agit pas correctement. Les Leds s'allument pendant un très court instant puis s'éteignent.

Je commence des tests de non régression sur mon robot afin de ne pas perdre de temps à revenir en arrière. En testant chaque fonction individuellement puis en les assemblant petit à petit, je peux identifier plus facilement les problèmes. 