<?php
class zwei_update_ctrl extends CI_Controller{

function __construct(){
parent::__construct();
$this->load->model('zwei_update_model');
}



function show_student_id_params($w_id, $p_id, $msg_id) {
		$data['msg_id'] = $msg_id;
		$data['anzahl'] = '2Anzahl';
        $data['students'] = $this->zwei_update_model->show_students();
        $data['single_student'] = $this->zwei_update_model->show_student_id($w_id, $p_id);
        $this->load->view('zwei_update_view', $data);
    }
	
function show_student_id() {
        $w_id = $this->uri->segment(3);
        $p_id = $this->uri->segment(4);
		$this->show_student_id_params($w_id, $p_id, -1);
    }

function update_student_id1() {
		$w_id= $this->input->post('dw_id');
    	$p_id= $this->input->post('dp_id');
    	$data = array(
            '2Anzahl' => $this->input->post('danzahl')
        );
     	$this->zwei_update_model->update_student_id1($w_id, $p_id, $data);
		$this->show_student_id_params($w_id, $p_id, 1);
    }

}
?>
 
