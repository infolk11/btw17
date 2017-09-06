<?php
	$servername = "localhost",
	$username = "root";
	$password = "";
	$dbname= "btw_17";

	$wl = $_POST['wahllokal'];
	$parteien = $_POST['partei'];
	$kandidaten = $_POST['kandidat'];
	
	$conn = new mysqli($servername, $username, $password, $dbname);
	if ($conn->connect_error) {
		die("Connection failed".$conn->connect_error);
	
	}
	//sql parteien abfragen
	$sql = "SELECT P_ID FROM Partei"
	$result = $conn->exec($sql);
	// in result speichern
	
	//for each über result
	foreach($result as $r){
		$sql = "INSERT INTO 2stimme(W_ID,P_ID,2Anzahl) VALUES ("$wl", " + $r + ", " + $parteien[$r] + "$)";
		$conn->exec($sql);
	}
		//insert wert von p[result] wo p_id: result 
	
	$sql = "SELECT D_ID FROM Direktkandidaten"
	$result = $conn->exec($sql);
	foreach($result as $r){
		$sql = "INSERT INTO 1stimme(W_ID, D_ID, 1Anzahl) VALUES ("$wl", " + $r + ", " + $kandidaten[$r] + "$)";
		$conn->exec($sql);
	}
?>

