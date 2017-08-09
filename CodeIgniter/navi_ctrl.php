<?php
class navi_ctrl extends CI_Controller{

function __construct(){
parent::__construct();

}
function load_navi_view(){
$this->load->view('navi_view');
}

}
?>