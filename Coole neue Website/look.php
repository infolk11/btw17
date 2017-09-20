<?php
include 'protected.php';
?>

<!DOCTYPE <!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
    <meta http-equiv="refresh" content="5">
</head>
<body>
<?php


include 'dbh.php';

$num_rows_old = $_SESSION['num_rows'];

if($stmt = $conn->prepare("SELECT * FROM changelog")) {
    $stmt->execute();
    //$n_rows = $stmt->num_rows;
    $stmt->bind_result($user_id, $time, $w_id);

    $_SESSION['num_rows'] = $stmt->num_rows;

    if ($num_rows_old <= $_SESSION['num_rows']) {
        
        for ($i = 0; $i <= $num_rows_old; $i++) {
            $stmt->fetch();
        }

        while($stmt->fetch()) {

            if($stmt2 = $conn->prepare("SELECT username FROM user WHERE id = ?")) {
                $stmt2->bind_param("i", $user_id);
                $stmt2->execute();
                $stmt2->bind_result($username);
                $stmt2->fetch();
                echo("Es ist ein neuer Eintrag in Wahllokal ".$w_id." vorhanden, dieser wurde von ".$username." angelegt");
            } else {
                echo($conn->errno." : ".$conn->error);
            }
        }
    } else {
        echo("Es sind keine neuen Einträge vorhanden");
    }
}


?>    
</body>
</html>