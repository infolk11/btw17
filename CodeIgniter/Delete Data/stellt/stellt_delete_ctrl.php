<?php
class stellt_delete_ctrl extends CI_Controller{
	
function __construct(){
parent::__construct();
$this->load->model('stellt_delete_model');
}

function show_student_id_params($p_id, $d_id, $msg_id) {
		$data['msg_id'] = $msg_id;
		$data['students'] = $this->stellt_delete_model->show_students();
		$data['single_student'] = $this->stellt_delete_model->show_student_id($p_id, $d_id);
		$this->load->view('stellt_delete_view', $data);
	}
	
// Function to Fetch selected record from database.
function show_student_id() {
        $p_id = $this->uri->segment(3);
        $d_id = $this->uri->segment(4);
		$this->show_student_id_params($p_id, $d_id, -1);
	}
	
// Function to Delete selected record from database.
function delete_student_id() {
        $p_id = $this->uri->segment(3);
        $d_id = $this->uri->segment(4);
		$this->stellt_delete_model->delete_student_id($p_id, $d_id);
		$this->show_student_id_params(-1, -1, 1);
	}
}
?>