<?php
class dkan_update_ctrl extends CI_Controller{
function __construct(){
parent::__construct();
$this->load->model('dkan_update_model');
}
function show_student_id_params($d_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->dkan_update_model->show_students();
        $data['single_student'] = $this->dkan_update_model->show_student_id($d_id);
        $this->load->view('dkan_update_view', $data);
    }
	
function show_student_id() {
        $d_id = $this->uri->segment(3);
		$this->show_student_id_params($d_id, -1);
    }
function update_student_id1() {
		$d_id= $this->input->post('dd_id');
    	$data = array(
			'Vorname' => $this->input->post('dvname'),
			'Name' => $this->input->post('dname'),
        );
     	$this->dkan_update_model->update_student_id1($d_id, $data);
		$this->show_student_id_params($d_id, 1);
    }
}
?>


