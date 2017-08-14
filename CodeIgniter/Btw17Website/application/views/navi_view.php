
<html>
    <head>
        <title>Navigation</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Navigation</h1><hr/> 
                <div id="1stimme">
					<p>Erststimme</p>
					<a href="<?php echo base_url() . "index.php/erst_insert_ctrl/show_view" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/erst_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/erst_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
                </div>
		<div id="zweitstimme">
					<p>Zweitstimme</p>
					<a href="<?php echo base_url() . "index.php/zwei_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/zwei_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/zwei_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
                </div> 
		<div id="partei">
					<p>Partei</p>
					<a href="<?php echo base_url() . "index.php/part_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/part_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/part_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
					<div id="partei">
                </div> 
		<div id="direktkandidaten">
					<p>Direktkandidaten</p>
					<a href="<?php echo base_url() . "index.php/dkan_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/dkan_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/dkan_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
					<div id="dkan">
		</div> 
		<div id="stellt">
					<p>Stellt</p>
					<a href="<?php echo base_url() . "index.php/stellt_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/stellt_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
					<div id="stellt">
					
                </div>
		<div id="wahllokal">
					<p>Wahllokal</p>
					<a href="<?php echo base_url() . "index.php/wahl_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/wahl_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/wahl_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
               </div> 	
            </div> 
        </div>
    </body>
</html>
