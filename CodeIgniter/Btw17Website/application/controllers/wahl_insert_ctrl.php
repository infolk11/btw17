<?php
class wahl_insert_ctrl extends CI_Controller {
function __construct() {
parent::__construct();
$this->load->model('wahl_insert_model');
}
function index() {
//Setting values for tabel columns
$data = array(
'W_ID' => $this->input->post('dw_id'),
'W_Bezeichnung' => $this->input->post('dbez'),
'PLZ' => $this->input->post('dplz'),
'Straße' => $this->input->post('dstr'),
'Wahlberechtigte' => $this->input->post('dber'),
'Wahlbeteiligung' => $this->input->post('dbet'),
);
//Transfering data to Model
$this->wahl_insert_model->form_insert($data);
$data['message'] = 'Daten erfolgreich eingegeben!';
//Loading View
$this->load->view('wahl_insert_view', $data);
}
function show_view() {
//Loading View
$this->load->view('wahl_insert_view');
}
}
?>