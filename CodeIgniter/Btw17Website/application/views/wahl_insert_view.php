<html>
    <head>
        <title>wahl_insert</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/styles.css" ?>">
    </head> 
<body>
        <div id="container">
            <div id="wrapper">
				<h1>Wahllokale</h1><hr/>
				<?php if (isset($message)) { ?>
				<CENTER><h3 style="color:green;">Daten erfolgreich eingegeben!</h3></CENTER><br>
				<?php } ?>

				<?php echo form_open('wahl_insert_ctrl'); ?>
				<?php echo form_label('W_ID :'); ?> <?php echo form_error('dw_id'); ?><br/>
				<?php echo form_input(array('name' => 'dw_id')); ?><br/>

				<?php echo form_label('W_Bezeichnung :'); ?> <?php echo form_error('dbez'); ?><br/>
				<?php echo form_input(array('name' => 'dbez')); ?><br/>

				<?php echo form_label('PLZ :'); ?> <?php echo form_error('dplz'); ?><br/>
				<?php echo form_input(array('name' => 'dplz')); ?><br/>
				
				<?php echo form_label('Straße :'); ?> <?php echo form_error('dstr'); ?><br/>
				<?php echo form_input(array('name' => 'dstr')); ?><br/>
				
				<?php echo form_label('Wahlberechtigte :'); ?> <?php echo form_error('dber'); ?><br/>
				<?php echo form_input(array('name' => 'dber')); ?><br/>
				
				<?php echo form_label('Wahlbeteiligung :'); ?> <?php echo form_error('dbet'); ?><br/>
				<?php echo form_input(array('name' => 'dbet')); ?><br/>

				<?php echo form_submit(array('value' => 'Anlegen')); ?>
		    <p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a></p>
				<?php echo form_close(); ?><br/>

            </div> 
        </div>

</body>
</html>