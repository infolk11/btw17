<?php
class zwei_update_model extends CI_Model{
function show_students(){
$query = $this->db->get('2stimme');
$query_result = $query->result();
return $query_result;
}
function show_student_id($w_id, $p_id){
        $this->db->select('*');
        $this->db->from('2stimme');
        $this->db->where('W_ID', $w_id);
        $this->db->where('P_ID', $p_id);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }
function update_student_id1($w_id, $p_id, $data){
  	 $this->db->where('W_ID', $w_id);
 	 $this->db->where('P_ID', $p_id);
     $this->db->update('2stimme', $data);  
    }
 
}
?>