<!DOCTYPE <!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<?php

include 'protected.php';
include 'dbh.php';

if($stmt = $conn->prepare("SELECT * FROM changelog")) {
    $stmt->execute();
    $n_rows = $stmt->num_rows;
    $stmt->bind_result($user_id, $time, $w_id);

}





?>    
</body>
</html>