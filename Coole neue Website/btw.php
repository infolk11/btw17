<?php

$servername = "";
$username = "";
$password = "";
$database = "_wp_BTW_DE_17";

$conn = new mysqli($servername, $username, $password, $database);

if (!$conn) {
    die ("Connection failed: ".$conn->conn_error);
}

?>