<?php
class zwei_insert_model extends CI_Model{
function __construct() {
parent::__construct();
}
function form_insert($data){
// Inserting in Table(2Stimme) of Database(wahl_17)
$this->db->insert('2Stimme', $data);
}
}
?>