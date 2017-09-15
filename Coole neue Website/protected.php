<?php

session_start();
if (!isset($_SESSION['id'])) {
    die('bitte <a href="index.php"> einloggen </a>');
}

$userid = $_SESSION['id'];

?>