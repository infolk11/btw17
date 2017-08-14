
<html>
    <head>
        <title>Erst_Update</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Erststimme</h1><hr/> 
                <div id="menu">
                    <p>&nbsp&nbsp W-ID / D-ID </p>
                    <!--Fetching Names Of All Students From Database-->
					<?php foreach ($students as $student): ?>
						<li><a href="<?php echo base_url() . "index.php/erst_update_ctrl/show_student_id/" . $student->W_ID . "/" . $student->D_ID; ?>">
							<?php echo $student->W_ID; ?> / <?php echo $student->D_ID; ?></a></li>
					<?php endforeach; ?>
					<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a><p/>
                </div>
                <div id="detail">
					<!--Fetching All Details of Selected Student From Database And Showing In a Form-->
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/erst_update_ctrl/update_student_id1"?>">
							<br/><br/>
                            <label>Aktueller Datensatz (W-ID/D-ID):</label><br/> 
                            <label><?php echo $student->W_ID . " / " . $student->D_ID; ?></label><br/> 
							
							<br/>
                            <label>Stimmen:</label><br/> 
                            <input type="text" name="danzahl" value="<?php echo $student->$anzahl; ?>"><br/>

                            <input type="submit" id="submit" name="dsubmit" value="Update">

							<?php if (isset($msg_id) and ($msg_id == 1)) { ?>
								<br/>
								<label style="color:green;">Daten erfolgreich aktualisiert</label>
							<?php } ?>
							
                            <input type="text" id="hide" name="dw_id" value="<?php echo $student->W_ID; ?>">
                            <input type="text" id="hide" name="dd_id" value="<?php echo $student->D_ID; ?>">
                        </form>
                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>
