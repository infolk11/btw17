
    <head>
        <title>Partei_Update</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Partei</h1><hr/> 
                <div id="menu">
                    <p>&nbsp&nbsp P-ID / Name </p>               
					<?php foreach ($students as $student): ?>
						<li><a href="<?php echo base_url() . "index.php/part_update_ctrl/show_student_id/" . $student->P_ID ?>">
							<?php echo $student->P_ID; ?> / <?php echo $student->P_Bezeichnung; ?></a></li>
					<?php endforeach; ?>
			<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a><p/>
                </div>
                <div id="detail">				
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/part_update_ctrl/update_student_id1"?>">
							<br/><br/>
                            <label>Aktueller Datensatz (P-ID/Name):</label><br/> 
                            <label><?php echo $student->P_ID . " / " . $student->P_Bezeichnung; ?></label><br/> 
							
							<br/>
                            <label>Name:</label><br/> 
                            <input type="text" name="dbez" value="<?php echo $student->P_Bezeichnung; ?>"><br/>
							
							<label>Farbe:</label><br/> 
                            <input type="text" name="dfarbe" value="<?php echo $student->Farbe; ?>"><br/>
							
							<label>Listenplätze:</label><br/> 
                            <input type="text" name="dlplatz" value="<?php echo $student->Listenplaetze; ?>"><br/>
                            <input type="submit" id="submit" name="dsubmit" value="Update">
							<?php if (isset($msg_id) and ($msg_id == 1)) { ?>
								<br/>
								<label style="color:green;">Daten erfolgreich aktualisiert</label>
							<?php } ?>
							
                            <input type="text" id="hide" name="dp_id" value="<?php echo $student->P_ID; ?>">
                        </form>
                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>
