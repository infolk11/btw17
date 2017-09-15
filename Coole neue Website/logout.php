<?php

session_start();
session_destroy();
echo ("logout erfolgreich!");
header("Location: index.php");
?>