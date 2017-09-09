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
	$e ="SELECT P_Bezeichnung, 2Anzahl FROM Partei P, 2stimme S WHERE
		W_ID = '".$wl."'
		AND
		P.P_ID = S.P_ID;";
	$p = mysqli_query($conn, $e);
	$e ="SELECT Vorname, Name, 1Anzahl FROM Direktkandidaten D, 1stimme S WHERE
		W_ID = '".$wl."'
		AND
		D.D_ID = S.D_ID;";
	$d = mysqli_query($conn, $e);
	echo "<html>
			<head>
			<style>
				th, td {
					padding: 5px;
				}
			</style>
			</head>
			<body>
			Eingabe erfolgreich! :D <br>
			Sie haben folgende Daten eingegeben (Bitte überprüfen sie diese nochmal):<br>
				<table>
				 <tr>
					<th>Parteien</th>
					<th>Stimmen</th>
				 </tr>";
	while($row = $p->fetch_assoc()) {
			echo "<tr>
					<td>".$row["P_Bezeichnung"]."</td>
					<td>".$row["2Anzahl"]."</td> 
				 </tr>
				 ";
		} 
	echo "		</table> 
				<table>
				 <tr>
					<th>Direktkandidaten</th>
					<th>Stimmen</th>
				 </tr>";
	while($row = $d->fetch_assoc()) {
			echo "<tr>
					<td>".$row["Vorname"]." ".$row["Name"]."</td>
					<td>".$row["1Anzahl"]."</td> 
				 </tr>";
		} 
	
	
	echo ' 	</table>
			<br>
			 <a href="Updateauswahl.php" style="font-size:20px;">Fehler gemacht?</a> 				
			</body>
		<html>';
		
?>
