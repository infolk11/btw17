<?php
class wahl_delete_ctrl extends CI_Controller{
	
function __construct(){
parent::__construct();
$this->load->model('wahl_delete_model');
}

function show_student_id_params($w_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->wahl_delete_model->show_students();
        $data['single_student'] = $this->wahl_delete_model->show_student_id($w_id);
        $this->load->view('wahl_delete_view', $data);
    }
	
function show_student_id() {
        $w_id = $this->uri->segment(3);
		$this->show_student_id_params($w_id, -1);
    }

// Function to Delete selected record from database.
function delete_student_id() {
        $w_id = $this->uri->segment(3);
		$this->wahl_delete_model->delete_student_id($w_id);
		$this->show_student_id_params(-1, 1);
	}
}
?>