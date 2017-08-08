<?php
class part_delete_ctrl extends CI_Controller{
	
function __construct(){
parent::__construct();
$this->load->model('part_delete_model');
}

function show_student_id_params($p_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->part_delete_model->show_students();
        $data['single_student'] = $this->part_delete_model->show_student_id($p_id);
        $this->load->view('part_delete_view', $data);
    }
	
function show_student_id() {
        $p_id = $this->uri->segment(3);
		$this->show_student_id_params($p_id, -1);
    }

// Function to Delete selected record from database.
function delete_student_id() {
        $p_id = $this->uri->segment(3);
		$this->part_delete_model->delete_student_id($p_id);
		$this->show_student_id_params(-1, 1);
	}
}
?>