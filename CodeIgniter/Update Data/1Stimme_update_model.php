<?php
class 1Stimme_update_model extends CI_Model{
function show_students(){
$query = $this->db->get('1stimme');
$query_result = $query->result();
return $query_result;
}
function show_student_id($data){
        $this->db->select('*');
        $this->db->from('1stimme');
        $this->db->where('W_ID', $data);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }
function update_student_id1($id,$data){
     $this->db->where('W_ID', $id);
     $this->db->update('1stimme', $data);  
    }
 
}
?>
