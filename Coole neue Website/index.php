<?php
    session_start();
?>

<!DOCTYPE <html>
<html>

<head>
    <meta charset = "UTF-8">
    <title>index</title>

</head>

<body>

<?php
    if (!isset($_SESSION['id'])) {
        //keine session id
        echo '  <form action="login.php" method="POST">
                    <input type="text" name="username" maxlength="256" placeholder="Benutzername"> <br>
                    <input type="password" name="pwd" placeholder="Passwort"> <br>
                    <input type="checkbox" name="debug" value="true">Debug <br>
                    <button type="reset">reset</button> <br>
                    <br>
                    <button type="submit">Einloggen</button>
                </form>';
    }
    else {
        if($_SESSION['debug']) {
            echo '<h1> Debugmodus aktiviert </h1>';
        }

        if($_SESSION['id'] == 1) {
            echo 'Benutzer <a href="admin.php">hinzufügen</a><br>';
        }
        //login erfolgreich
        echo '  <h4>Login erfolgreich!</h4>
                Ergebnisse <a href="insertauswahl.php">eingeben</a><br>
                Eingaben <a href="updateauswahl.php">korrigieren</a><br>
                <br>
                <form action="logout.php">
                    <button>logout</button>
                </form>
                ';
    }
?>
</body>
</html>