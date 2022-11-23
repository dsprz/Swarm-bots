#!/bin/bash
file="mysqlsampledatabase.sql"
currentDay=$(date +%Y-%m-%d)
currentTime=$(date +%H-%M-%S)
maxFileNumber=5
savingDirectory="/home/jimmy/Documents/sql_td/saves"
backupName="mysqlsampledatabase-$currentDay-$currentTime.sql"
password=$(cat password)
######################Create bz2
if [ ! -d "saves" ];
then
	mkdir $savingDirectory
	chmod 777 $savingDirectory #j'aimerais ne pas faire de faire chmod
fi
echo $password
###la commande qui suit n'est clairement pas la meilleure façon de faire parce qu'il faut mettre son vrai mot de passe après -p
mysqldump -u root -p classicmodels >>$savingDirectory/$backupName 2>>erreur.txt
bzip2 -k -f ./saves/$backupName
rm ./saves/$backupName


#####################Create logs
maxLines=10
logFile="/var/log/dump-mysql/dump-mysql.log"
numberOfLines=$(cat $logFile | wc -l)
echo La sauvegarde de $file a bien été effectuée le $currentDay à $currentTime >> $logFile
if [ $numberOfLines -gt $maxLines ]; then
	sed '1d' $logFile 2>>erreur.txt
fi

####################Delete oldest bz2
numberOfFiles=$(ls ./saves | wc -l)
if [ "$numberOfFiles"  -gt "$maxFileNumber" ];

then
	rm $savingDirectory/$(ls -t $savingDirectory | tail -1)
fi
