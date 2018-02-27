/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
  // Complete this function
  // Do not write the main method
  if(!head) return false;
  Node* hare = head;
  Node* tort = head;
  while(hare && tort){
    if( hare->next ){
      hare = hare->next->next;
    } else return false;
    
    if(hare == tort) return true;    
    
    tort = tort->next;    
  }
  return false;
}

