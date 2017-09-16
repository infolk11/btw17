<?php

session_start();

include 'dbh.php';

$username = $_POST['username'];
$pwd = $_POST['pwd'];

$stmt = $conn->prepare("SELECT * FROM `user` WHERE `username` = (?) AND `password` = (?) ");
$stmt->bind_param("ss", $username, $pwd);


//execute
$stmt->execute();
// bind result variables
$stmt->bind_result($fetched_id, $fetched_username, $fetched_pwd);
//$result = $stmt->get_result();
//$row = $result->fetch_assoc();
$stmt->fetch();

while($stmt->fetch()) {
    if (password_verify($pwd, $fetched_pwd)) {
        //login erfolgreich
        $_SESSION['id'] = $fetched_id;
        header("Location: index.php");
        $stmt->close();
        $conn->close();
    }
}


  //die('<h1>Benutzername oder Passwort ungültig!</h1> <br>
  //    Bitte erneut <a href="index.php"> einloggen</a>');
  die("Error: ".$stmt->error);

  $stmt->close();
  
  $conn->close();

?>