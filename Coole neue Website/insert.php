<?php
	$servername = "localhost";
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
	$sql = "SELECT p_id FROM partei"
	$result = mysqli_query($conn, $sql);
	// in result speichern
	
	//for each über result
	foreach($result as $r){
		$sql = "INSERT INTO 2stimme(w_id,p_id,2anzahl) VALUES ("$wl", " + $r + ", " + $parteien[$r] + "$)";
		$conn->mysqli_query($conn, $sql);
	}
		//insert wert von p[result] wo p_id: result 
	
	$sql = "SELECT d_id FROM direktkandidaten"
	$result = mysqli_query($conn, $sql);
	foreach($result as $r){
		$sql = "INSERT INTO 1stimme(w_id,d_id,danzahl) VALUES ("$wl", " + $r + ", " + $kandidaten[$r] + "$)";
		$conn->mysqli_query($conn, $sql);
	}
?>
