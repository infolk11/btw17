<?php

class erst_update_model_only extends CI_Model{

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

function update_student_id1($w_id, $d_id, $data){
  	 $this->db->where('W_ID', $w_id);
 	 $this->db->where('D_ID', $d_id);
     $this->db->update('1stimme', $data);  
    }
 
}

?>
