<?php
	$servername = "localhost";
	$username = "root";
	$password = "";
	$dbname= "btw_17";

	#$wl = $_REQUEST['wahllokal'];
		
	$conn = new mysqli($servername, $username, $password, $dbname);
	if ($conn->connect_error) {
		die("Connection failed".$conn->connect_error);
	}
	$sql = "SELECT W_Bezeichnung, W_ID FROM Wahllokal";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '<!DOCTYPE html>
				<html>
					<!-- <meta charset="utf-8"/> -->
					<head>
						
						<title> Wahllokalauswahl </title>
					</head>
					<body>
						<form action = "Insert.php" method="post">
							<label for="wahllokal">Wählen sie ein Wahllokal aus:</label>
							<select name="wahllokal" width="100px">';
		while($row = $result->fetch_assoc()) {
			echo "<option value = ".$row['W_ID'].">".$row["W_Bezeichnung"]."</option>";
		}
		echo'				</select>';
	}else {
		echo "Keine Wahllokale gefunden";
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
			echo "<tr>
					<td>".$row["P_Bezeichnung"]."</td>
					<td> <input type='text' name='partei[".$row["P_ID"]."]'> </td> 
				 </tr>";
		}
		echo'				</table>';
	}else {
		echo "Keine Parteien gefunden";
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
					<td> <input type='text' name='kandidat[".$row["D_ID"]."]'> </td> 
				 </tr>";
		}
		echo'				</table>
							<button type ="submit" name="submit">Absenden</button>
						</form>
					</body>
				<html>';
	}else {
		echo "Keine Parteien gefunden";
	}
	$conn->close();	
?>
