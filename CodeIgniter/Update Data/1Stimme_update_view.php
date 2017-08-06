<html>
    <head>
        <title>Update Data In Database Using CodeIgniter</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/1Stimme_update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Daten Updaten: Erststimme </h1><hr/> 
                <div id="menu">
                    <p>W-ID &nbsp;&nbsp;&nbsp;&nbsp; D-ID </p>
                    <!--Fetching Names Of All Students From Database-->
					<ol>
                        <?php foreach ($students as $student): ?>
                            <li><a href="<?php echo base_url() . "index.php/1Stimme_update_ctrl/show_student_id/" . $student->W_ID; ?>"> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <?php echo $student->W_ID; ?></a></li>
                        <?php endforeach; ?>
                    </ol>
                </div>
                <div id="detail">
					<!--Fetching All Details of Selected Student From Database And Showing In a Form-->
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/1Stimme_update_ctrl/update_student_id1"?>">
                            <label id="hide">Id :</label><br/> 
                            <input type="text" id="hide" name="dwid" value="<?php echo $student->W_ID; ?>"><br/>      

                            <label>Direktkandidaten-ID :</label><br/> 
                            <input type="text" name="ddid" value="<?php echo $student->D_ID; ?>"><br/>    

                            <label>Stimmen :</label><br/> 
                            <input type="text" name="d1anzahl" value="<?php echo $student->$anzahl; ?>"><br/>

                            
							
							 <!-- <label>Wahllokal :</label><br/> 
                            <input type="text" name="dmobile" value="<?php echo $student->W_ID; ?>"><br/>
                            <!-- <label>Address :</label><br/> 
                            <input type="text" name="daddress" value="<?php echo $student->student_address; ?>"><br/>
							
							-->

                            <input type="submit" id="submit" name="dsubmit" value="Update">
                        </form>

                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>
