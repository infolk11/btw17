<!DOCTYPE html>
<html>
<head>

<body>
	<h3>Login</h3>

	<form action="/index.php method="post">	
		<label>Benutzer</label>
		<input type="text" placeholder="" name="benutzer" required>
		<input type="password" placeholder="" name="password" required>
		<button type="submit">Login </button>
	</form>

<?php

session_start();

$login_true = false;

//sql zeugs
$servername = "";
$username = "";
$password = "";

$conn = mysqli_connect($servername, $username, $password);
if (!$conn) {
	die("Connection failed");
else {
	$statement = conn->prepare();
}



?>


</body>
</html>