<?php

class Test_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('Test_insert_model');
}
function index() {

//Setting values for tabel columns
$data = array(
'W_ID' => $this->input->post('dwid'),
'D_ID' => $this->input->post('ddid'),
'1Anzahl' => $this->input->post('danzahl'),

);
//Transfering data to Model
$this->Test_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('Test_insert_view', $data);
}
}



?>