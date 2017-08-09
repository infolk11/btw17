<html>
    <head>
        <title>stellt_Insert</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/styles.css" ?>">
    </head> 
<body>
        <div id="container">
            <div id="wrapper">
				<h1>Stellt-Beziehung</h1><hr/>
				<?php if (isset($message)) { ?>
				<CENTER><h3 style="color:green;">Daten erfolgreich eingegeben!</h3></CENTER><br>
				<?php } ?>

				<?php echo form_open('stellt_insert_ctrl'); ?>
				<?php echo form_label('P_ID :'); ?> <?php echo form_error('dp_id'); ?><br/>
				<?php echo form_input(array('name' => 'dp_id')); ?><br/>

				<?php echo form_label('D_ID :'); ?> <?php echo form_error('dd_id'); ?><br/>
				<?php echo form_input(array('name' => 'dd_id')); ?><br/>

				<?php echo form_submit(array('value' => 'Anlegen')); ?>
				<p><a href="<?php echo base_url() . "index.php/navi_ctrl/load_navi_view"; ?>">Zurück zur Navigation</a></p>
				<?php echo form_close(); ?><br/>
				
            </div> 
        </div>

</body>
</html>