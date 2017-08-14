<?php
class wahl_update_ctrl extends CI_Controller{

function __construct(){
parent::__construct();
$this->load->model('wahl_update_model');
}



function show_student_id_params($w_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->wahl_update_model->show_students();
        $data['single_student'] = $this->wahl_update_model->show_student_id($w_id);
        $this->load->view('wahl_update_view', $data);
    }
	
function show_student_id() {
        $w_id = $this->uri->segment(3);
		$this->show_student_id_params($w_id, -1);
    }

function update_student_id1() {
		$w_id= $this->input->post('dw_id');
    	$data = array(
			'W_Bezeichnung' => $this->input->post('dbez'),
			'PLZ' => $this->input->post('dplz'),
			'Straße' => $this->input->post('dstr'),
			'Wahlberechtigte' => $this->input->post('dber'),
			'Wahlbeteiligung' => $this->input->post('dbet')
        );
     	$this->wahl_update_model->update_student_id1($w_id, $data);
		$this->show_student_id_params($w_id, 1);
    }

}
?>
