<?php

class stellt_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('stellt_insert_model');
}


function index() {

//Setting values for tabel columns
$data = array(
'P_ID' => $this->input->post('dp_id'),
'D_ID' => $this->input->post('dd_id'),

);
//Transfering data to Model
$this->stellt_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('stellt_insert_view', $data);
}

function show_view() {

//Loading View
$this->load->view('stellt_insert_view');
}

}



?>