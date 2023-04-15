Séance 20

J'ai décidé de changer d'approche pour faire revenir les petits robots vers l'araignée.
Au lieu d'avoir 5 récepteurs sur chaque robot, je vais en mettre juste 2 et faire tourner mon robot jusqu'à ce qu'il détecte une tension analogique, puis je me dirigerai au mieux vers cette tension.
Les deux récepteurs sont là pour différencier la gauche et la droite, et aussi parce que si je mets 5 récepteurs, j'ai bien peur de ne pas avoir assez de pins analogiques pour mes autres modules. De plus c'est plus facile de juste en avoir 2 au niveau de la place disponible sur mon robot, et aussi du temps que je dois investir juste pour en fabriquer.

J'ai aussi revu mes méthodes de soudure. Lorsque je dénude les fils, je les dénude très peu. En effet, le fait de trop les dénuder rend les fils fragiles lorsque je les bouge, et ils ont tendance à se casser.
En plus de cela j'ai changé de type de fil, je suis passé à des fils de fer au lieu des fils de cuivre.

J'ai aussi réussi à convetir la tension analogique reçue en tension numérique sur mon Arduino, avant pour une raison que j'ignore totalement, mon Arduino renvoyait 0. J'ai demandé à Christian Peter pourquoi c'était le cas, il a vérifié mon montage et mes signaux de sortie, je n'avais rien changé, et par magie l'entrée analogique ne renvoyait plus 0. 

J'ai eu quelques problèmes sur la soudure d'un récepteur, je ne sais pas ce qu'il s'est passé, mais j'ai perdu pas mal de temps à essayer de le réparer parce qu'il ne recevait aucun signal. J'avais vérifié les branchements, j'ai mis un peu plus de soudure et j'ai tourné le potentiomètre, et ça marchait correctement.

Pour faire tenir ma carte Arduino de façon stable, j'ai imprimé en 3D un petit boîtier pour Arduino qui pourra se visser sur un support plat. Ce boitier sert surtout à stabiliser ma carte, elle n'arrêtait pas de bouger parce qu'elle tenait sur ses pics de soudure.

Résultat de cette semaine: j'ai tous les composants pour finir tout un robot. Il me suffira de monter le deuxième exactement de la même façon.