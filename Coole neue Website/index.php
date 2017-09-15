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
                    <button type="submit">Einloggen</button>
                </form>';
    }
    else {
        //login erfolgreich
        echo '  login erfolgreich <br>
                <form action="logout.php">
                    <button>logout</button>
                </form>';
    }
?>
</body>
</html>