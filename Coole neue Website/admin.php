<?php

session_start();

if ($_SESSION['id'] !== 1) {
    include 'logout.php';
} else {
    include 'dbh.php';
    //benutzer hinzufügen
    echo '  <!DOCTYPE html>
            <html>
            <head>
                <meta charset = "UTF-8">
                <title>Verwaltung</title>
            </head>

            <body>
                <h2>Benutzer hinzufügen</h2><br>
                <form  method="POST" action=<?php echo htmlspecialchars ($_SERVER["PHP_SELF"]); ?>
                    username:<br>
                    <input type="text" name="username"><br>
                    password:<br>
                    <input type="password" name="password"><br>
                    repeat password:<br>
                    <input type="password" name"password_2"><br>
                    <input type="submit">
                </form>
            </body>
            </html>';


}


?>