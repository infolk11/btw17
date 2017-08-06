<html>

<body>
<h1>Bundestagswahlen 2017: Erststimme</h1><hr/>
<?php if (isset($message)) { ?>
<CENTER><h3 style="color:green;">Daten erfolgreich eingegeben!</h3></CENTER><br>
<?php } ?>

<?php echo form_open('Test_insert_ctrl'); ?>
<?php echo form_label('W_ID :'); ?> <?php echo form_error('dwid'); ?><br />
<?php echo form_input(array('name' => 'dwid')); ?><br />

<?php echo form_label('D_ID :'); ?> <?php echo form_error('ddid'); ?><br />
<?php echo form_input(array('name' => 'ddid')); ?><br />

<?php echo form_label('1Anzahl :'); ?> <?php echo form_error('danzahl'); ?><br />
<?php echo form_input(array('name' => 'danzahl')); ?><br />

<!-- <?php echo form_label('Student Address :'); ?> <?php echo form_error('daddress'); ?><br />
<?php echo form_input(array('name' => 'daddress')); ?><br />
-->


<?php echo form_submit(array('value' => 'Submit')); ?>
<?php echo form_close(); ?><br/>

</body>
</html>