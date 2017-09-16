<?php
	
	include 'protected.php';
	
	$servername = "";
	$username = "";
	$password = "";
	$database = "_wp_BTW_DE_17";
	

	#$wl = $_REQUEST['wahllokal'];
		
	$conn = new mysqli($servername, $username, $password, $dbname);
	if ($conn->connect_error) {
		die("Connection failed".$conn->connect_error);
	}
	$sql = "SELECT W_Bezeichnung, W_ID FROM Wahllokal ORDER BY W_Bezeichnung";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '<!DOCTYPE html>
				<html>
					<!-- <meta charset="utf-8"/> -->
					<head>
						
						<title> Wahllokalauswahl </title>
					</head>
					<body>
						<form action = "update.php" method="post">
							<label for="wahllokal">Wählen sie ein Wahllokal aus:</label>
							<select name="wahllokal" width="100px">';
		while($row = $result->fetch_assoc()) {
			echo "<option value = ".$row['W_ID'].">".$row["W_Bezeichnung"]."</option>";
		}
		echo'				</select><br><br>';
	}else {
		echo "Keine Wahllokale gefunden <br>";
	}
		echo '				<label for="pok">Möchten sie eine Partei oder einen Kandidaten updaten?</label>
							<select name="pok" width="100px">
							    <option value= 1>Kandidat updaten</option>
								<option value= 0>Partei updaten</option>
								
							</select><br><br>';
	$sql = "SELECT P_Bezeichnung, P_ID FROM Partei";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '		 		<label for="partei">Wählen sie eine Partei aus:</label>
							<select name="partei" width="100px">';
		while($row = $result->fetch_assoc()) {
			echo "<option value = ".$row['P_ID'].">".$row["P_Bezeichnung"]."</option>";
		}
		echo'				</select><br><br>';
	}else {
		echo "Keine Parteien gefunden <br>";
	}
	
	$sql = "SELECT Vorname, Name, D_ID FROM Direktkandidaten";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '		 		<label for="kandidat">Wählen sie einen Kandidaten aus:</label>
							<select name="kandidat" width="100px">';
		while($row = $result->fetch_assoc()) {
			echo "<option value = ".$row['D_ID'].">".$row["Vorname"]." ".$row["Name"]."</option>";
		}
		echo'				</select><br><br>
							<label for="stimmen">Stimmenanzahl:</label>
							<input type="text" name="stimmen"><br><br>
							<button type ="submit" name="submit">Absenden</button>
						</form>
					</body>
				<html>';
	}else {
		echo "Keine Kandidaten gefunden <br>";
	}

	if ($_SESSION['debug']) {
		echo ("Error number ".$conn->errno." : ".$conn->error);
	}
				
	$conn->close();	
	
?>
