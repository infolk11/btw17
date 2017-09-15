<?php

session_start();

include 'dbh.php';

$stmt = $conn->prepare("SELECT * FROM user WHERE username = (?) AND password = (?) ");
$stmt->bind_param("ss", $username, $pwd);

$username = $_POST['username'];
$pwd = $_POST['pwd'];

$stmt->execute();
$result = $stmt->get_result();
$row = $result->fetch_assoc();

if ($row !== false && password_verify($pwd, $row['password'])) {
    //login erfolgreich
    $_SESSION['id'] = $row['id'];
} else {
    die("Benutzername oder Passwort ungültig!");
}

//header("Location: index.php");

?>