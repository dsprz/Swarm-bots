Pour commencer, j'ai fait au mieux pour contrebalancer les variations de luminosité de ma Pixy en diminuant le nombre d'images par seconde, en jouant sur la tolérance des couleurs, en activant le mode "Auto-White balance" et "Auto-White balance on power up", et en mettant plus de block filtering au prix de la vitesse de détection. Dans un environnement avec une luminosité stable, ça ne devrait pas causer de problème, sauf si par exemple un nuage vers brusquement cacher le Soleil, auquel cas il y aura peut-être des problèmes de reconnaissance le temps qu'Auto-White balance fait effet.

J'ai commencé à écrire le code pour diriger et ramasser le robot vers son objet.
Pour expliquer le fonctionnement du code, tous mes objets ont la même forme et la même hauteur, 80 mm de hauteur (la même chose qu'un petit stick de colle de la marque UHU). 
Je me place à une distance connue de ma Pixycam, ici je me suis placé à environ 125 mm, c'est-à-dire au niveau où ma pince peut attraper cet objet. Je branche mon Arduino et ma Pixy, puis grâce aux informations que les fonctions intégrées de Pixy et que le Serial Monitor me donnent, je peux obtenir la hauteur en pixel de l'objet, c'est-à-dire la hauteur que ma Pixycam voit.
Mon but est de déterminer la distance focale de ma Pixycam afin de calculer n'importe quelle distance entre ma Pixy et un objet une fois que ce-dernier est détecté.
Si je note H la hauteur de mon objet, D la distance mesurée entre ma Pixy et mon objet, P la hauteur en pixel de mon objet vue par la caméra à un instant t et F la distance focale que je dois calculer, j'ai la formule suivante : F = (DP)/H.
F est alors une constante que je peux utiliser pour calculer une distance inconnue.
Si je note D' une distance inconnue par rapport à la Pixy, j'ai : D' = (FH)/P.

Maintenant, pour ramasser correctement mon objet, je dois centrer ma caméra sur l'objet. Pour ce faire, la Pixy me donne déjà accès à la hauteur de la frame <i>frameHeight</i> et la largeur de la frame <i>frameWidth</i>. Il faut aussi savoir que la détection de la Pixy se fait par block, un block étant un rectangle qui entoure au mieux l'objet qu'on détecte. Je peux avoir la hauteur et la largeur du block et la position en X et en Y grâce aux fonctions intégrées de Pixy. X et Y donnent l'intersection des diagonales du rectangle, donc X = (longueur du rectangle)/2 et Y = (largeur du rectangle)/2.
Lorsque je détecte un objet à une position quelconque, je dois centrer le block. Tant que X n'est pas égal à frameWidth/2 (plus ou moins une petite marge), je tourne à droite ou à gauche. Tant que Y n'est pas égal à frameHeight/2 (toujours avec une marge), j'avance ou je recule.
Lorsque X et Y sont bien centrés et que D'= 125mm avec une marge, le robot s'arrête et attrape l'objet.

En combinant ces deux morceaux, je peux me diriger vers mon objet et l'attraper à chaque fois de la même façon.

Concernant le HC12, j'ai réussi à envoyer l'objet à attraper d'une Arduino à l'autre. J'ai simulé l'araignée donnant des ordres aux robots. Comme les essaims de robot imitent très souvent la nature, je me suis imaginé une conversation entre humains sans ambiguïté possible de cette forme : 
1) A appelle B 
2) B confirme le fait d'avoir entendu A (l"équivalent du "oui, je peux vous rendre service ?")
3) A donne une tâche à B
4) B effectue la tâche

En appliquant ceci aux robots, chaque robot a un nom unique : K, U pour mes petits robots, S pour l'araignée. Voici ce que j'ai fait pour l'instant :
1) S appelle K par son nom
2) K confirme avoir entendu S en rappelant S
3) S envoie le numéro (sous la forme d'un char) de la signature* de l'objet
4) K reçoit ce numéro et le converit en int.

K peut maintenant aller chercher l'objet correspondant à la signature reçue.

*Chaque objet enregistré dans la Pixy possède une signature numérotée de 1 à 7. La Pixy peut en stocker 7 au maximum, donc elle peut reconnaître 7 objets prédéfinis. Dans la pratique c'est ce que j'utilise pour reconnaître mes objets, mais la Pixy peut en reconnaître beaucoup plus que 7 grâce au mode "Color Coded Components". Elle peut reconnaître des codes couleurs. Pour expliquer avec un exemple, imaginons qu'on empile 2, 3 voire 4 LEGO de couleurs différentes, la Pixy peut reconnaître chaque permutation de couleurs de LEGO. Je n'utilise pas ce mode de la Pixy parce qu'il n'y a pas de signature associée, ce qui rend la communication plus difficile (et de plus tous mes objets sont monochromes).

En testant mes programmes, je crois avoir cassé le chip d'une de mes Arduinos. L'Arduino est bien alimentée, elle fait bien tourner le programme qui a été téléversé, mais je ne peux plus la reprogrammer. Lorsque je téléverse mon code, l'IDE est coincé sur "Uploading..." mais n'upload pas. Après avoir fait des recherches sur Internet, je pensais que c'était un problème lié à mon PC, à mon câble USB, ou le code en lui-même, mais j'ai essayé de téléverser le même code sur une autre Arduino et l'opération a parfaitement bien fonctionné. Donc ce n'était ni mon PC, ni mon câble USB, ni mon programme mais bien mon Arduino qui est défectueuse (alors qu'elle marchait très bien 20 minutes de cela). Apparemment, mes câbles USB ne rentrent pas bien dans le chip USB de cette Arduino, normalement il y a un petit "click" sonore et le câble est censé aller "jusqu'au bout", mais ce n'était pas le cas. Les connexions électriques sont suffisantes pour l'alimenter, mais pas pour la reprogrammer via USB.