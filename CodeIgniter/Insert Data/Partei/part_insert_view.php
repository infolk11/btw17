<html>
    <head>
        <title>Insert</title>
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

				<?php echo form_open('part_insert_ctrl'); ?>
				<?php echo form_label('P_ID :'); ?> <?php echo form_error('dp_id'); ?><br/>
				<?php echo form_input(array('name' => 'dp_id')); ?><br/>

				<?php echo form_label('P_Bezeichnung :'); ?> <?php echo form_error('dbez'); ?><br/>
				<?php echo form_input(array('name' => 'dbez')); ?><br/>

				<?php echo form_label('Farbe :'); ?> <?php echo form_error('dfar'); ?><br/>
				<?php echo form_input(array('name' => 'dfar')); ?><br/>
				
				<?php echo form_label('Listenplätze :'); ?> <?php echo form_error('dliste'); ?><br/>
				<?php echo form_input(array('name' => 'dliste')); ?><br/>
								
				<?php echo form_submit(array('value' => 'Anlegen')); ?>
				<?php echo form_close(); ?><br/>

            </div> 
        </div>

</body>
</html>