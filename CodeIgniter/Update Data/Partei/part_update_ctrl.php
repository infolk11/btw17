<?php
class part_update_ctrl extends CI_Controller{
function __construct(){
parent::__construct();
$this->load->model('part_update_model');
}
function show_student_id_params($p_id, $msg_id) {
		$data['msg_id'] = $msg_id;
        $data['students'] = $this->part_update_model->show_students();
        $data['single_student'] = $this->part_update_model->show_student_id($p_id);
        $this->load->view('part_update_view', $data);
    }
	
function show_student_id() {
        $p_id = $this->uri->segment(3);
		$this->show_student_id_params($p_id, -1);
    }
function update_student_id1() {
		$p_id= $this->input->post('dp_id');
    	$data = array(
			'P_Bezeichnung' => $this->input->post('dbez'),
			'Farbe' => $this->input->post('dfarbe'),
			'Listenplaetze' => $this->input->post('dlplatz'),
			
        );
     	$this->part_update_model->update_student_id1($p_id, $data);
		$this->show_student_id_params($p_id, 1);
    }
}
?>


