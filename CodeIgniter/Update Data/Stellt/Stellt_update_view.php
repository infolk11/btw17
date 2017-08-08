<html>
    <head>
        <title>Stellt</title>
        <link href='http://fonts.googleapis.com/css?family=Marcellus' rel='stylesheet' type='text/css'>
        <link rel="stylesheet" type="text/css" href="<?php echo base_url(). "css/update.css" ?>">
    </head> 
    <body>
        <div id="container">
            <div id="wrapper">
                <h1>Daten Updaten: Stellt </h1><hr/> 
                <div id="menu">
                    <p>P-ID &nbsp;&nbsp;&nbsp;&nbsp; D-ID </p>
                    
					<ol>
                        <?php foreach ($students as $student): ?>
                            <li><a href="<?php echo base_url() . "index.php/Stellt_update_ctrl/show_student_id/" . $student->P_ID; ?>"> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <?php echo $student->P_ID; ?></a></li>
                        <?php endforeach; ?>
                    </ol>
                </div>
                <div id="detail">
					<!--Fetching All Details of Selected Student From Database And Showing In a Form-->
                    <?php foreach ($single_student as $student): ?>
                        <p>Bearbeite die Daten & Klicke den 'Update' Button</p>
                        <form method="post" action="<?php echo base_url() . "index.php/Stellt_update_ctrl/update_student_id1"?>">
                            <label id="hide">Partei-ID:</label><br/> 
                            <input type="text" id="hide" name="dwid" value="<?php echo $student->P_ID; ?>"><br/>      

                            <label>Direktkandidaten-ID :</label><br/> 
                            <input type="text" name="ddid" value="<?php echo $student->D_ID; ?>"><br/>    

                          

                            <input type="submit" id="submit" name="dsubmit" value="Update">
                        </form>

                    <?php endforeach; ?>
                </div> 
            </div> 
        </div>
    </body>
</html>