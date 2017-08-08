
<?php
class Stellt_update_ctrl extends CI_Controller{
function __construct(){
parent::__construct();
$this->load->model('Stellt_update_model');
}
function show_student_id() {
	    
        $id = $this->uri->segment(3);
        $data['students'] = $this->Stellt_update_model->show_students();
        $data['single_student'] = $this->Stellt_update_model->show_student_id($id);
        $this->load->view('Stellt_update_view', $data);
       
    }
function update_student_id1() {
       $id= $this->input->post('dpid');
       $data = array(
            'P_ID' => $this->input->post('dpid'),
            'D_ID' => $this->input->post('dd_id'),
        );
       $this->Stellt_update_model->update_student_id1($id,$data);
       $this->show_student_id();
    }
}
?>