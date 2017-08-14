<html>
    <head>
        <title>erst_insert</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/styles.css" ?>">
    </head> 
<body>
        <div id="container">
            <div id="wrapper">
				<h1>Erststimme</h1><hr/>
				<?php if (isset($message)) { ?>
				<CENTER><h3 style="color:green;">Daten erfolgreich eingegeben!</h3></CENTER><br>
				<?php } ?>

				<?php echo form_open('erst_insert_ctrl'); ?>
				<?php echo form_label('W_ID :'); ?> <?php echo form_error('dw_id'); ?><br/>
				<?php echo form_input(array('name' => 'dw_id')); ?><br/>

				<?php echo form_label('D_ID :'); ?> <?php echo form_error('dd_id'); ?><br/>
				<?php echo form_input(array('name' => 'dd_id')); ?><br/>

				<?php echo form_label('Anzahl :'); ?> <?php echo form_error('danzahl'); ?><br/>
				<?php echo form_input(array('name' => 'danzahl')); ?><br/>

				<?php echo form_submit(array('value' => 'Anlegen')); ?>
		   <p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a></p>
				<?php echo form_close(); ?><br/>

            </div> 
        </div>

</body>
</html>