from flask import Flask, render_template

app = Flask(__name__)

#@app.route('/')
#def index():
    # render your html template
   # return render_template('index.html')

#@app.route('/something')
#def do_something():
   # print ('do something here')
   # return

@app.route('/')
def index():
    return 'Index Page'

@app.route('/hello')
def hello():
    return  render_template('index.html')
@app.route('/eingabe')
def eingabe():
    import mysql.connector
    Servername = 'localhost'
    Benutzer = 'root'
    Passwort = ''
    Datenbank = 'btw17'
    ver = mysql.connector.connect(host=Servername)
    ver.cmd_change_user(username=Benutzer, password=Passwort)
    ver.database = Datenbank
    cursor = ver.cursor()
    Wahllokal1 = input("Wahllokal? ")
    WahllokalID = 'SELECT W_ID from Wahllokal where W_Bezeichnung="' + Wahllokal1 + '";'
    cursor.execute(WahllokalID)
    w_idvor = cursor.fetchall()
    for row in w_idvor:
        w_id = str(row[0])
    Parteien = 'SELECT P_ID, P_Bezeichnung from partei;'
    cursor.execute(Parteien)
    Partei = cursor.fetchall()

    for row in Partei:
        p_id = str(row[0])
        Parteiname = row[1]
        Stimme2 = input("Wie viele Stimmen für die Partei " + Parteiname + "?")
        Partei2 = 'INSERT INTO `2stimme`(`W_ID`, `P_ID`, `2Anzahl`) VALUES (' + w_id + ', ' + p_id + ', ' + Stimme2 + ');'
        cursor.execute(Partei2)

    Kandidaten = 'SELECT D_ID, Vorname, Name FROM direktkandidaten;'
    cursor.execute(Kandidaten)
    Kandidat = cursor.fetchall()
    for row in Kandidat:
        d_id = str(row[0])
        vorname = row[1]
        name = row[2]
        Stimme1 = str(input("Wie viele Stimmen für den Kandidaten " + vorname + " " + name + "?"))
        kandidat2 = 'INSERT INTO `1stimme`(`W_ID`, `D_ID`, `1Anzahl`) VALUES (' + w_id + ', ' + d_id + ', ' + Stimme1 + ');'
        cursor.execute(kandidat2)
    cursor.close();
    ver.commit();
    ver.close
    return 'Eingabe'
if __name__ == '__main__':
    app.run()