#include <iostream>
struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
  if(!head){
    head = new Node();
    head->next = NULL;
    head->prev = NULL;
    head->data = data;
    return head;
  }
  Node* hPtr = head;
  Node* nextPtr;
  Node* prevPtr;

  if (data < head->data){
    Node* nn = new Node(); 
    nn->data = data;
    nn->prev = NULL;
    nn->next = head;
    head->prev = nn;
    return nn;
  }

  while(head->next){
    if( data < head->next->data){
      nextPtr = head->next;//3
      prevPtr = head;
      head->next = new Node();
      head = head->next;
      head->next = nextPtr;
      head->prev = prevPtr;
      head->data = data;
      nextPtr->prev=head;
      prevPtr->next=head;
      return hPtr;
    } else{
      head = head->next;//2.2
    }
  }
  prevPtr = head;//1
  head->next = new Node();
  head = head->next;
  head->data = data;
  head->prev = prevPtr;
  head->next = NULL;
  return hPtr;
}

void readNode(Node *head){
  if(head){
    std::cout << head->data << " ";
    readNode(head->next);
  }
}

int main(){
  
  Node* nod1 = new Node();
  Node* nod2 = new Node();
  int n1[] = {1,2,3,4,5,6};
  int n12[] = {100,0,13,2,4,5,24,1,1,13};
  int n2[] = {5,6,9,10,21};
  nod1 = NULL;
  nod2 = NULL;
  for(int i = 0; i < 10; i++){
    nod1 = SortedInsert(nod1,n12[i]);
  }
  readNode(nod1);
  std::cout << "\n";
  return 0;
}
