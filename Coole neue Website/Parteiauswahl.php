<?php
	$servername = "localhost";
	$username = "root";
	$password = "";
	$dbname= "btw_17";

	$wl = $_REQUEST['wahllokal'];
		
	$conn = new mysqli($servername, $username, $password, $dbname);
	if ($conn->connect_error) {
		die("Connection failed".$conn->connect_error);
	}
	$sql = "SELECT W_Bezeichnung, W_ID FROM Wahllokal";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '<!DOCTYPE html>
				<html>
					<head>
						<title> Wahllokalauswahl </title>
					</head>
					<body>
						<form action = "Insert.php" method="post">
							<select name="wahllokal">';
		while($row = $result->fetch_assoc()) {
			echo "<option name = " + $row['w_id'] + ">"+ $row["w_bezeichnung"] +"</option>";
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
					<td>"+ $row["p_bezeichnung"] + "</td>
					<td> <input type='text' name='partei[" + $row["p_id"] + " ]'> </td> 
				 </tr>";
		}
		echo'				</table>';
	}else {
		echo "Keine Parteien gefunden";
	}
	
	$sql = "SELECT Vorname, Name, d_id FROM Direktkandidaten";
	$result = mysqli_query($conn, $sql);
	if($result->num_rows>0) {
		echo '				<table name="Kandidat">
								<tr>
									<th>Kandidat:</th>
									<th> </th>
								</tr>';
		while($row = $result->fetch_assoc()) {
			echo "<tr>
					<td>"+ $row["vorname"] + " " + $row['name']+ "</td>
					<td> <input type='text' name='kandidat[" + $row["d_id"] + " ]'> </td> 
				 </tr>";
		}
		echo'				</table>
							<button type ="submit" name="submit">
						</form>
					</body>
				<html>';
	}else {
		echo "Keine Parteien gefunden";
	}
	$conn->close();	
?>
