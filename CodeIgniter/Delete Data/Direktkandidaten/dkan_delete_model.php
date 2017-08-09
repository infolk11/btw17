<?php
class dkan_delete_model extends CI_Model{
	
function show_students(){
		$query = $this->db->get('Direktkandidaten');
		$query_result = $query->result();
		return $query_result;
	}
function show_student_id($d_id){
        $this->db->select('*');
        $this->db->from('Direktkandidaten');
        $this->db->where('D_ID', $d_id);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }
function delete_student_id($d_id){
  	 $this->db->where('D_ID', $d_id);
     $this->db->delete('Direktkandidaten');  
	}
	
}
?> 