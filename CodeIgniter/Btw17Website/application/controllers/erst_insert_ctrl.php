<?php

class erst_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('erst_insert_model');
}


function index() {

//Setting values for tabel columns
$data = array(
'W_ID' => $this->input->post('dw_id'),
'D_ID' => $this->input->post('dd_id'),
'1Anzahl' => $this->input->post('danzahl'),

);
//Transfering data to Model
$this->erst_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('erst_insert_view', $data);
}

function show_view() {

//Loading View
$this->load->view('erst_insert_view');
}

}



?>