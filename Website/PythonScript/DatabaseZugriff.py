import mysql.connector # neue Bibliothek

Servername = 'localhost' # Rechnername (localhost ist dein eigener Rechner)
Benutzer   = 'root'
Passwort   = ''
Datenbank  = 'btw17'

# Verbindung mit der Datenbank
#con = mysql.connector.connect(host=Servername)
#con.cmd_change_user(username = Benutzer, password = Passwort)
#con.database = Datenbank
ver = mysql.connector.connect(host=Servername)
ver.cmd_change_user(username = Benutzer, password = Passwort)
ver.database = Datenbank
cursor = ver.cursor()
Wahllokal1 = input("Wahllokal? ")
Partei= input("Partei?")
StimmenP= input("Stimmen Partei?")
Kanidat= input("Kandidat?")
KanidatStimmen=input("KandidatStimmen?")
WahllokalID = "SELECT W_ID from Wahllokal where W_Bezeichnung="Wahllokal1";"

cursor.execute(WahllokalID)
w_id = cursor.fetchall ()
for row in w_id :
  print row[0], row[1];


cursor.close()
ver.commit()
ver.close