<html>
    <head>
        <title>Wahl_Update</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Wahllokal</h1><hr/> 
                <div id="menu">
                    <p>&nbsp&nbsp W-ID / Name </p>
                    <!--Fetching Names Of All Students From Database-->
					<?php foreach ($students as $student): ?>
						<li><a href="<?php echo base_url() . "index.php/wahl_update_ctrl/show_student_id/" . $student->W_ID ?>">
							<?php echo $student->W_ID; ?> / <?php echo $student->W_Bezeichnung; ?></a></li>
					<?php endforeach; ?>
			<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a><p/>
                </div>
                <div id="detail">
					<!--Fetching All Details of Selected Student From Database And Showing In a Form-->
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/wahl_update_ctrl/update_student_id1"?>">
							<br/><br/>
                            <label>Aktueller Datensatz (W-ID/Name):</label><br/> 
                            <label><?php echo $student->W_ID . " / " . $student->W_Bezeichnung; ?></label><br/> 
							
							<br/>
                            <label>Name:</label><br/> 
                            <input type="text" name="dbez" value="<?php echo $student->W_Bezeichnung; ?>"><br/>
							
							<label>PLZ:</label><br/> 
                            <input type="text" name="dplz" value="<?php echo $student->PLZ; ?>"><br/>
							
							<label>Straße:</label><br/> 
                            <input type="text" name="dstr" value="<?php echo $student->Straße; ?>"><br/>
							
							<label>Wahlberechtigte:</label><br/> 
                            <input type="text" name="dber" value="<?php echo $student->Wahlberechtigte; ?>"><br/>
							
							<label>Wahlbeteiligung:</label><br/> 
                            <input type="text" name="dbet" value="<?php echo $student->Wahlbeteiligung; ?>"><br/>

                            <input type="submit" id="submit" name="dsubmit" value="Update">
							<?php if (isset($msg_id) and ($msg_id == 1)) { ?>
								<br/>
								<label style="color:green;">Daten erfolgreich aktualisiert</label>
							<?php } ?>
							
                            <input type="text" id="hide" name="dw_id" value="<?php echo $student->W_ID; ?>">
                        </form>
                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>
