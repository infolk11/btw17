
    <head>
        <title>Dkan_Update</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Direktkandidaten</h1><hr/> 
                <div id="menu">
                    <p>&nbsp&nbsp P-ID / Name </p>               
					<?php foreach ($students as $student): ?>
						<li><a href="<?php echo base_url() . "index.php/dkan_update_ctrl/show_student_id/" . $student->D_ID ?>">
							<?php echo $student->D_ID; ?> / <?php echo $student->Vorname; ?> <?php echo $student->Name; ?></a></li>
					<?php endforeach; ?>
			<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a><p/>
                </div>
                <div id="detail">				
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/dkan_update_ctrl/update_student_id1"?>">
							<br/><br/>
                            <label>Aktueller Datensatz (D_ID/Name):</label><br/> 
                            <label><?php echo $student->D_ID . " / " . $student->Vorname;  $student->Name;  ?></label><br/> 
							
							<br/>
                            <label>Vorname:</label><br/> 
                            <input type="text" name="dvname" value="<?php echo $student->Vorname; ?>"><br/>
							
							<label>Name:</label><br/> 
                            <input type="text" name="dname" value="<?php echo $student->Name; ?>"><br/>
							
                            <input type="submit" id="submit" name="dsubmit" value="Update">
							<?php if (isset($msg_id) and ($msg_id == 1)) { ?>
								<br/>
								<label style="color:green;">Daten erfolgreich aktualisiert</label>
							<?php } ?>
							
                            <input type="text" id="hide" name="dd_id" value="<?php echo $student->D_ID; ?>">
                        </form>
                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>
