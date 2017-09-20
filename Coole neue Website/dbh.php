<?php

$servername = "172.18.0.4";
$username = "website";
$password = "cebit17";
$database = "website";

$conn = new mysqli($servername, $username, $password, $database);

if (!$conn) {
    die ("Connection failed: ".$conn->conn_error);
}

?>
