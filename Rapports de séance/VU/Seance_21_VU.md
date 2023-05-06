Séance 21

Ma pince s'est un peu fissurée parce que la tête de vis qui la maintient au robot est trop grosse. Le problème c'est lorsque je commande électroniquement ma pince, la partie fissurée est "emportée" par le mouvement du servomoteur, ce qui crée un jeu supplémentaire sur les engrenages de la pince, ce qui a pour effet de les "délier" :  l'autre claw n'est pas entrainée par le servomoteur et les mouvements répétés risquent de casser le servomoteur. 
J'ai réussi à régler le problème en mettant beaucoup de colle, maintenant le mouvement de la pince est très fluide.

Pour rajouter de la friction à mes roues afin qu'elles puissent mieux rouler (elles avaient un peu de mal parce que la surface des roues était trop lisse), j'ai collé du papier de verre sur les roues. La différence est clairement visible.

Les fils de soudure se sont encore cassés. Je les ai soudés à nouveau, mais cette fois j'ai mis de la colle chaude en plus de la soudure. La colle chaude ne gêne pas la conduction, et j'espère que ce sera assez pour empêcher les fils de casser une enième fois.

Il y a un émetteur que j'ai soudé récemment qui ne marche pas, j'ai du faire une erreur dans les soudures. J'ai décidé de ne pas l'utiliser et de me contenter juste de 2 émetteurs.

Les tests de non-régression se sont avérés être un succès. Toutes les fonctionnalités suivantes marchent correctement :

- Déplacements vers un objet détecté
- Communication via le HC-12 avec l'araignée
- Retour vers l'araignée avec le système émetteurs-récepteurs

J'ai imprimé un support pour mettre mes récepteurs. Au début, j'avais fait des trous pour y mettre deux vis afin de le maintenir au robot, sauf que j'ai réalisé que la vis allait toucher les soudures et potentiellement court-circuiter les récepteurs. Je voulais à tout prix ne pas les casser, et malheureusement le Fablab n'a pas de vis plastique.
J'ai opté pour un simple scotch double face. Ce n'est pas la meilleure solution, mais je ne voulais pas utiliser de colle trop forte pour pouvoir retirer le support si je devais le déplacer autre part.

J'ai décidé de ne pas mettre de HC-SR04 sur mon robot parce que la fréquence des ultrasons est de 40 kHz, soit la même fréquence que celle de mon système émetteurs-récepteurs. 

J'ai récupéré l'araignée de Koralie. Lorsque j'ai commencé les tests pour lier mon robot et l'araignée, une patte de l'araignée a commencé à se fissurer : je l'ai remarqué parce qu'il y avait un bruit inhabituel de crack lorsqu'elle se déplaçait. La fissure est assez petite pour être réparée avec de la colle forte, mais un petit peu plus et je perdais une patte.