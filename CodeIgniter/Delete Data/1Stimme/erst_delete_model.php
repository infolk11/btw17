<?php

class erst_delete_model extends CI_Model{
	
function show_students(){
		$query = $this->db->get('1stimme');
		$query_result = $query->result();
		return $query_result;
	}

function show_student_id($w_id, $d_id){
        $this->db->select('*');
        $this->db->from('1stimme');
        $this->db->where('W_ID', $w_id);
        $this->db->where('D_ID', $d_id);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }

function delete_student_id($w_id, $d_id){
  	 $this->db->where('W_ID', $w_id);
 	 $this->db->where('D_ID', $d_id);
     $this->db->delete('1stimme');  
	}
}
?> 