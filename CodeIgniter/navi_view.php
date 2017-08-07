
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
					<a href="<?php echo base_url() . "index.php/insert_ctrl/show_view" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
                </div>
                <div id="wahllokal">
					<p>Wahllokal</p>
					<a href="<?php echo base_url() . "index.php/wahl_insert_ctrl/schow_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/wahl_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/wahl_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
                </div> 
				<div id="zweitstimme">
					<p>Zweitstimme</p>
					<a href="<?php echo base_url() . "index.php/zwei_insert_ctrl/show_view/-1/-1" ?>">Datensatz einfügen</a><br/>
					<a href="<?php echo base_url() . "index.php/zwei_update_ctrl/show_student_id/-1/-1" ?>">Datensatz aktualisieren</a><br/>
					<a href="<?php echo base_url() . "index.php/zwei_delete_ctrl/show_student_id/-1/-1" ?>">Datensatz löschen</a><br/>
                </div> 
            </div> 
        </div>
    </body>
</html>
