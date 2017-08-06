<?php
class 1Stimme_update_ctrl extends CI_Controller{
function __construct(){
parent::__construct();
$this->load->model('1Stimme_update_model');
}
function show_student_id() {
	    
        $id = $this->uri->segment(3);
		$data['anzahl'] = '1Anzahl';
        $data['students'] = $this->1Stimme_update_model->show_students();
        $data['single_student'] = $this->1Stimme_update_model->show_student_id($id);
        $this->load->view('1Stimme_update_view', $data);
       
    }
function update_student_id1() {
       $id= $this->input->post('dwid');
       $data = array(
            //'W_ID' => $this->input->post('dwid'),
            'D_ID' => $this->input->post('ddid'),
            '1Anzahl' => $this->input->post('d1anzahl'),
            //'Student_Address' => $this->input->post('daddress')
        );
       $this->1Stimme_update_model->update_student_id1($id,$data);
       $this->show_student_id();
    }
}
?>
