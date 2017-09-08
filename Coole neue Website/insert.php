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
	$sql = "SELECT P_ID FROM Partei";
	$result = mysqli_query($conn, $sql);
	// in result speichern
	
	//for each über result
	while ($r = $result->fetch_assoc()){
		$sql = "INSERT INTO 2stimme(W_ID, P_ID, 2Anzahl) VALUES (".$wl.", ".$r["P_ID"].", ".$parteien[$r["P_ID"]].")";
		mysqli_query($conn, $sql);
	}
	unset ($r);
		//insert wert von p[result] wo p_id: result 
	
	$sql = "SELECT D_ID FROM Direktkandidaten";
	$result = mysqli_query($conn, $sql);
	while ($r = $result->fetch_assoc()){
		$sql = "INSERT INTO 1stimme(W_ID, D_ID, 1Anzahl) VALUES (".$wl.", ".$r["D_ID"].", ".$kandidaten[$r["D_ID"]].")";
		mysqli_query($conn, $sql);
	}
	echo "Eingabe erfolgreich! :D"

?>
