<?php

session_start();

if ($_SESSION['id'] !== 1) {
    include 'logout.php';
} else {
    
    echo '  <!DOCTYPE html>
            <html>
            <head>
                <meta charset = "UTF-8">
                <title>Verwaltung</title>
            </head>
            <body>';
    
    //echo htmlspecialchars($_SERVER["PHP_SELF"]);

    include 'dbh.php';
    
    //if (isset($_POST['username']) && isset($_POST['password']) && isset($_POST['password2'])) {
    if (isset($_POST['username']) && isset($_POST['password']) && isset($_POST['password2'])) {
        if ($_POST['password'] !== $_POST['password2']) {
            echo 'die Passwörter stimmen nicht überein, es wurde kein Benutzer hinzugefügt!';
            //keine query ausführen
        } else {
            $password_hash = password_hash($_POST['password'], PASSWORD_DEFAULT);
         
            
            if ($stmt = $conn->prepare("INSERT INTO `user` (`username`, `password`) VALUES ((?), (?))")) {
                $stmt->bind_param("ss", $_POST['username'], $password_hash);
                $stmt->execute();
                echo("Benutzer ".$_POST['username']." wurde hinzugefügt.");
            } else {
                echo ("Error number ".$conn->errno." : ".$conn->error);
            }
        }
    } else {

    }
    //benutzer hinzufügen
    echo '
                <h2>Benutzer hinzufügen</h2><br>
                <form action="" method="POST">
                    username:<br>
                    <input type="text" name="username"><br>
                    password:<br>
                    <input type="password" name="password"><br>
                    repeat password:<br>
                    <input type="password" name="password2"><br>
                    <input type="submit">
                </form>
                <br>
                <form action="logout.php">
                    <button>logout</button>
                </form>
            </body>
            </html>';
    
    if ($_SESSION['debug']) {
        echo ("Error number ".$conn->errno." : ".$conn->error);
    }
    $conn->close();
}
?>