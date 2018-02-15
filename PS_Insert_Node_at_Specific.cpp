#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
  
	//Pointer to head
  Node* hPtr = head;
    
  // Complete this method
  Node* nodeInsert = new Node();
  nodeInsert->data = data;
    
  if(!head){
    head = new Node();
    head->data = data;
    head->next = NULL;
    return head;
  }
  if(position == 0){
    nodeInsert->next = head; 
    return nodeInsert;
  }
  while(head->next && --position){
    head = head->next;
  }
    
  
  nodeInsert->next = head->next;
  head->next = nodeInsert; 
  
  return hPtr;        
}

void readNode(Node *head){
  if(head){
    cout << head->data << " ";
    readNode(head->next);
  }
}
void deleteNodes(Node *head){
  if(head){
    deleteNodes(head->next);
    delete head;
  }
}

int main(){
  Node mynode;
  Node* hd = &mynode;
  int d = 3;
  hd = NULL;
  hd = InsertNth(hd,3,0);
  hd = InsertNth(hd,5,1);
  hd = InsertNth(hd,4,2);
  hd = InsertNth(hd,2,3);
  hd = InsertNth(hd,10,1);
  
  
  readNode(hd);
  std::cout << "\n";
 
  deleteNodes(hd); 
  return 0;
}
