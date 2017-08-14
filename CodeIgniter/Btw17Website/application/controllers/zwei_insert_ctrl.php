<?php

class zwei_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('zwei_insert_model');
}


function index() {

//Setting values for tabel columns
$data = array(
'W_ID' => $this->input->post('dw_id'),
'P_ID' => $this->input->post('dp_id'),
'2Anzahl' => $this->input->post('danzahl'),

);
//Transfering data to Model
$this->zwei_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('zwei_insert_view', $data);
}

function show_view() {

//Loading View
$this->load->view('zwei_insert_view');
}

}



?>