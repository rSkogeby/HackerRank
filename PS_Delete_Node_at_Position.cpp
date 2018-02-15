#include <iostream>
using namespace std;

Node* InsertNth(Node *head, int data, int position)
{
	//Pointer to head
  Node* hPtr = head;
    
  if(!head){
    return head;
  }

  if(position == 0){
    Node* nH = head->next;
    delete head; 
    return nH;
  }
  while(head->next && --position){
    head = head->next;
  }
  Node* nH = head->next->next;
  delete head->next;
  head->next = nH;
  
  return hPtr;        
}
