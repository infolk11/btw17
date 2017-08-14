<?php

class wahl_delete_model extends CI_Model{
	
function show_students(){
		$query = $this->db->get('Wahllokal');
		$query_result = $query->result();
		return $query_result;
	}

function show_student_id($w_id){
        $this->db->select('*');
        $this->db->from('Wahllokal');
        $this->db->where('W_ID', $w_id);
        $query = $this->db->get();
        $result = $query->result();
        return $result;  
    }

function delete_student_id($w_id){
  	 $this->db->where('W_ID', $w_id);
     $this->db->delete('Wahllokal');  
	}
	
}
?> 