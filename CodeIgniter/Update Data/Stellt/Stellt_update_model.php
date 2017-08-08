<?php
class Stellt_update_model extends CI_Model{
function show_students(){
$query = $this->db->get('Stellt');
$query_result = $query->result();
return $query_result;
}
function show_student_id($data){
        $this->db->select('*');
        $this->db->from('Stellt');
        $this->db->where('P_ID', $data);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }
function update_student_id1($id,$data){
     $this->db->where('P_ID', $id);
     $this->db->update('Stellt', $data);  
    }
 
}
?>