<?php
class update_ctrl extends CI_Controller{

function __construct(){
parent::__construct();
$this->load->model('update_model');
}



function show_student_id_params($w_id, $d_id, $msg_id) {
		$data['msg_id'] = $msg_id;
		$data['anzahl'] = '1Anzahl';
        $data['students'] = $this->update_model->show_students();
        $data['single_student'] = $this->update_model->show_student_id($w_id, $d_id);
        $this->load->view('update_view', $data);
    }
	
function show_student_id() {
        $w_id = $this->uri->segment(4);
        $d_id = $this->uri->segment(3);
		$this->show_student_id_params($w_id, $d_id, -1);
    }

function update_student_id1() {
		$w_id= $this->input->post('dw_id');
    	$d_id= $this->input->post('dd_id');
    	$data = array(
            '1Anzahl' => $this->input->post('danzahl')
        );
     	$this->update_model->update_student_id1($w_id, $d_id, $data);
		$this->show_student_id_params($w_id, $d_id, 1);
    }

}
?>
