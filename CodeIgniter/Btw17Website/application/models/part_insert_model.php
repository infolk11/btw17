<?php
class part_insert_model extends CI_Model{
function __construct() {
parent::__construct();
}
function form_insert($data){
// Inserting in Table(Partei) of Database(wahl_17)
$this->db->insert('Partei', $data);
}
}
?>