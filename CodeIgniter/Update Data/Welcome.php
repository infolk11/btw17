<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Welcome extends CI_Controller {

	/**
	 * Index Page for this controller.
	 *
	 * Maps to the following URL
	 * 		http://example.com/index.php/welcome
	 *	- or -
	 * 		http://example.com/index.php/welcome/index
	 *	- or -
	 * Since this controller is set as the default controller in
	 * config/routes.php, it's displayed at http://example.com/
	 *
	 * So any other public methods not prefixed with an underscore will
	 * map to /index.php/welcome/<method_name>
	 * @see https://codeigniter.com/user_guide/general/urls.html
	 */
	public function index()
	{
		//$this->load->view('update_view');
		//$this->load->view('update_ctrl');
		//$this->update_ctrl->show_student_id(-1);
		$this->load->model('update_model');
		

   
        $data['students'] = $this->update_model->show_students();
        $data['single_student'] = $this->update_model->show_student_id(-1);
        $this->load->view('update_view', $data);

	}
}
