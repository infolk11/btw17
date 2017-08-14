<?php

class part_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('part_insert_model');
}


function index() {

//Setting values for tabel columns
$data = array(
'P_ID' => $this->input->post('dp_id'),
'P_Bezeichnung' => $this->input->post('dbez'),
'Listenplaetze' => $this->input->post('dliste')

);
//Transfering data to Model
$this->part_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('part_insert_view', $data);
}

function show_view() {

//Loading View
$this->load->view('part_insert_view');
}

}



?>