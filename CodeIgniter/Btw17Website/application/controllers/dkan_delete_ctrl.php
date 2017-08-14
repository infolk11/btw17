<?php
class dkan_delete_ctrl extends CI_Controller{
	
function __construct(){
parent::__construct();
$this->load->model('dkan_delete_model');
}
function show_student_id_params($d_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->dkan_delete_model->show_students();
        $data['single_student'] = $this->dkan_delete_model->show_student_id($d_id);
        $this->load->view('dkan_delete_view', $data);
    }
	
function show_student_id() {
        $d_id = $this->uri->segment(3);
		$this->show_student_id_params($d_id, -1);
    }
// Function to Delete selected record from database.
function delete_student_id() {
        $d_id = $this->uri->segment(3);
		$this->dkan_delete_model->delete_student_id($d_id);
		$this->show_student_id_params(-1, 1);
	}
}
?>