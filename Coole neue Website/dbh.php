<?php

$servername = "127.0.0.1:3306";
$username = "website";
$password = "cebit17";
$database = "login";

$conn = new mysqli($servername, $username, $password, $database);

if (!$conn) {
    die ("Connection failed: ".$conn->conn_error);
}

?>