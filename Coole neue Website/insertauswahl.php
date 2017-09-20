<?php
	
	include 'protected.php';
	
	include 'btw.php';
	
		
	header ('content-type: text/html charset=utf-8');
	$sql = "SELECT W_Bezeichnung, W_ID FROM Wahllokal ORDER BY W_Bezeichnung";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '<!DOCTYPE html>
				<html>
					<head>
						
						<title> Wahllokalauswahl </title>
					</head>
					<body>
						<a href="updateauswahl.php" style="font-size:17px;">Daten falsch eingegeben?</a> <br><br>
						<form action = "insert.php" method="post">
							<label for="wahllokal">W&auml;hlen sie ein Wahllokal aus:</label>
							<select name="wahllokal" width="100px">';
		while($row = $result->fetch_assoc()) {
			echo "<option value = ".$row['W_ID'].">".$row["W_Bezeichnung"]."</option>";
		}
		echo'				</select>';
	}else {
		echo "Keine Wahllokale gefunden <br>";
	}
	
	$sql = "SELECT P_Bezeichnung, P_ID FROM Partei";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '				<table name="partei">
								<tr>
									<th>Parteien:</th>
									<th> </th>
								</tr>';
		while($row = $result->fetch_assoc()) {
			#parteilos
			if ($row["P_Bezeichnung"] == "parteilos") {
			}
			else{
			echo
				"<tr>
					<td>".$row["P_Bezeichnung"]."</td>
					<td> <input type='number' min='0' name='partei[".$row["P_ID"]."]'> </td> 
				 </tr>";
			}
		}
		echo'				</table><br>';
	}else {
		echo "Keine Parteien gefunden <br>";
	}
	
	$sql = "SELECT Vorname, Name, D_ID FROM Direktkandidaten";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '				<table name="Kandidat">
								<tr>
									<th>Kandidat:</th>
									<th> </th>
								</tr>';
		while($row = $result->fetch_assoc()) {
			echo "<tr>
					<td>".$row["Vorname"]." ".$row['Name']."</td>
					<td> <input type='number' min='0' name='kandidat[".$row["D_ID"]."]'> </td> 
				 </tr>";
		}
		echo'				</table>
							<button type ="submit" name="submit">Absenden</button>
						</form>';
	}else {
		echo "Keine Parteien gefunden <br>";
	}

	echo '	<form action="logout.php">
				<button>logout</button>
			</form>
			</body>
			</html>';

	if ($_SESSION['debug']) {
		echo ("Error number ".$conn->errno." : ".$conn->error);
	}

	$conn->close();	
?>
