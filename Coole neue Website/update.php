<?php
	
	include 'protected.php';
	
	include 'btw.php';
	

	$wl = $_POST['wahllokal'];
	$stimmen = $_POST['stimmen'];
	$partei = $_POST['partei'];
	$kandidat = $_POST['kandidat'];
	$pok = $_POST['pok'];
	header ("content-type: text/html charset=utf-8");

	if ($pok == 0 ){
		$sql = "UPDATE 2stimme
				SET 2Anzahl ='".$stimmen."'
				WHERE P_ID ='".$partei."' AND W_ID='".$wl."';";
		mysqli_query($conn, $sql);
		echo "Zweitstimme aktualisiert!<br>";
		
	}
	else {
		$sql = "UPDATE 1stimme
				SET 1Anzahl ='".$stimmen."'
				WHERE D_ID ='".$kandidat."' AND W_ID='".$wl."';";
				
		mysqli_query($conn, $sql);
		echo "Erststimme aktualisiert!<br>";
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
			Sie haben folgende Daten eingegeben (Bitte &uuml;berpr&uuml;fen sie diese nochmal):<br>
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
			 <a href="updateauswahl.php" style="font-size:20px;">Fehler gemacht?</a> 
			 <a href="insertauswahl.php" style="font-size:17px;">Weiter zum Daten eintragen!</a>
			 <form action="logout.php">
			 	<button>logout</button>
		 	</form>
			 </body>
		<html>';
		
	if ($_SESSION['debug']) {
		echo ("Error number ".$conn->errno." : ".$conn->error);
	}
	
	$conn->close();

?>
