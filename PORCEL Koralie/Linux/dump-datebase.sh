#!/bin/bash 
bzip2 -fk /home/ilarak/Documents/dataBase.sql		#enregistre le fichier en un fichier bz2 
nom=$(date +%Y-%m-%d-%H-%M-%S)				#nouveau nom de fichier			
mv dataBase.sql.bz2 Sauvegarde/$nom.bz2			#change le nom du fichier en la date, l’heure , les minutes et les secondes du jour


nombr=`ls Sauvegarde | wc -l`				#récupere le nombre de fichier dans le répértoir sauvegarde 
echo Sauvegarde du fichier $nom réussi>>/var/log/dump-mysql.log  #permet de mettre dans les log.
while [ $nombr -gt 5 ] #gt permet de faire : tant qu'il y a plus de 5 fichiers dans le dossier sauvegarde
do 
	nomFichierAncien=`ls -r Sauvegarde | tail -n 1` #pour récupérer le fichier le plus ancien
	rm Sauvegarde/$nomFichierAncien			#supprime ce fichier
			
	nombr=`ls Sauvegarde | wc -l` 			#recompte le nombre de fichier dans Sauvegarde

done