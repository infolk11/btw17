<?php

$servername = "";
$username = "";
$password = "";
$database = "login";

$conn = new mysqli($servername, $username, $password, $database);

if (!$conn) {
    die ("Connection failed: ".$conn->conn_error);
}

?>