<html>
<head>
	<title>Part_Delete</title>
	<link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
	<link href="<?php echo base_url()?>./css/delete.css" rel="stylesheet" type="text/css">
</head>
<body>
	<div id="container">
		<div id="wrapper">
			<h1>Partei</h1>
			<div id="menu">
				<p>&nbsp&nbsp P-ID / Name </p>
				<!--Fetching Names Of All Students From Database-->
				<?php foreach ($students as $student): ?>
					<li><a href="<?php echo base_url() . "index.php/part_delete_ctrl/show_student_id/" . $student->P_ID ?>">
						<?php echo $student->P_ID; ?> / <?php echo $student->P_Bezeichnung; ?></a></li>
				<?php endforeach; ?>
				<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a><p/>
			</div>
			<div id="detail">
				<!--====== Displaying Fetched Details from Database ========-->
				<?php foreach ($single_student as $student): ?>
					<p>Details</p>
					<label>P_ID&nbsp&nbsp: </label><?php echo $student->P_ID; ?><br/>
					<label>Name&nbsp&nbsp: </label><?php echo $student->P_Bezeichnung; ?><br/>
					<label>Farbe&nbsp&nbsp&nbsp&nbsp: </label><?php echo $student->Farbe; ?><br/>
					<label>Listenplätze: </label><?php echo $student->Listenplaetze; ?><br/>
					<!--====== Delete Button ========-->
					<a href="<?php echo base_url() . "index.php/part_delete_ctrl/delete_student_id/" . $student->P_ID ?>">
					<button>Delete</button></a>
				<?php endforeach; ?>
				<?php if (isset($msg_id) and ($msg_id == 1)) { ?>
					<br/>
					<br/>
					<br/>
					<label style="color:green;">Daten erfolgreich gelöscht</label>
				<?php } ?>
			</div>
		</div>
	</div>
</body>
</html>
