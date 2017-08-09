<?php

class stellt_delete_model extends CI_Model{
	
function show_students(){
		$query = $this->db->get('stellt');
		$query_result = $query->result();
		return $query_result;
	}

function show_student_id($p_id, $d_id){
        $this->db->select('*');
        $this->db->from('stellt');
        $this->db->where('P_ID', $p_id);
        $this->db->where('D_ID', $d_id);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }

function delete_student_id($p_id, $d_id){
  	 $this->db->where('P_ID', $p_id);
 	 $this->db->where('D_ID', $d_id);
     $this->db->delete('stellt');  
	}
}
?> 