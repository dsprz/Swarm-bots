To install MySQL open the command prompt and type:
	1)sudo apt update
	2)sudo apt install mysql-server
	3)mysql
	4)ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password' with 'password' being an actual password
	5)Set up a password with  mysql_secure_installation

To use the database :
	1)Download the database at https://www.mysqltutorial.org/wp-content/uploads/2018/03/mysqlsampledatabase.zip and extract it
	2)Connect to mysql -u root -p and enter your password
	3)Type : source path/to/your/sqlFile.sql
	4)show databases;

More info at https://www.mysqltutorial.org


To set up the logs, open the command prompt and type :
	1)sudo mkdir /var/log/dump-mysql/dump-mysql.log
	2)sudo chmod o+w

To setup dump-database.service and dump-datbase.timer, open the command prompt and :
	1)Move both files in /etc/systemd/system/ by typing : 
		sudo mv path/to/dump-database.service /etc/systemd/system/dump-database.service
		sudo mv path/to/dump-database.timer /etc/systemd/system/dump-database.timer
	2)sudo systemctl daemon-reload
	3)sudo systemctl enable dump-database.timer
	4)sudo systemctl start dump-database.timer
	5)To check the service status, type : sudo systemctl status dump-database.service




