<?php
class dkan_insert_ctrl extends CI_Controller {

function __construct() {
parent::__construct();
$this->load->model('dkan_insert_model');
}


function index() {

//Setting values for tabel columns
$data = array(
'Vorname' => $this->input->post('dvorname'),
'D_ID' => $this->input->post('dd_id'),
'Name' => $this->input->post('dname'),

);
//Transfering data to Model
$this->dkan_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('dkan_insert_view', $data);
}

function show_view() {

//Loading View
$this->load->view('dkan_insert_view');
}

}



?>