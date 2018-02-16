#include <iostream>
struct Node
{
   int data;
   struct Node *next;
};

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
	// Find matching addresses of next
	/*
	O(n^2) to O(2n)=O(n)

Start on 1
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL | [List #2] p--->q--->x
                     /
     [List #2] p--->q

  Iterators do asame amount of steps in the x-y-z part.
  However, if #1 and #2 are not of equal length, 
  they will be equal during the second loop
  This is because the paths preceding the tail of xyz, i.e. 
  a->b->c and p->q will have been traversed by both iterators. 

*/  
  Node* currentA = headA;
  Node* currentB = headB;
  while(currentA != currentB){
    
    if(!currentA->next){
      currentA = headB;
    } else {
      currentA = currentA->next;
    }
      
    if(!currentB->next){
      currentB = headA;
    } else {
      currentB = currentB->next;
    }
      
  
  }  
  
  return currentB->data;  
}

Node* RemoveDuplicates(Node* head){
// Makes all elements unique in a a list with monotonically increasing values.
  Node* hPtr = head;
  Node* nPtr;
  while(head->next){
    if(head->data == head->next->data){
      nPtr = head->next->next;
      delete head->next;
      head->next = nPtr;
    } else {
      head = head->next;
    }
  }
  return hPtr;
}

int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
  int lLength = 0;
  Node* hd = head;
	while(head->next){
	  head = head->next;
    lLength++;
	}
  head = hd;
  while(lLength-positionFromTail){
	  lLength--;
	  head = head->next;
  }
  return head->data;
}

Node* MergeLists(Node *headA, Node* headB){
  //int n1[] = {4,7,9};
  //int n2[] = {5,6,10,21};
  
  if(!headA && !headB) return NULL;
  else if(!headA) return headB;
  else if(!headB) return headA;
  
  if(headA->data < headB->data){ // On first enter in MergeLists :
    headA->next = MergeLists(headA->next,headB);//headA = 4, headB=5
  } else { //On second enter in MergeLists
    Node* currPtr = headB; // headA=7, headB = 5
    headB = headB->next; // headB = 6
    currPtr->next = headA; // currPtr->next = headA = 7
    headA = currPtr; // headA = 5, headA->next = 7
    headA->next = MergeLists(headA->next,headB);// 7,6
  }
  return headA;
}
Node* Insert(Node *head,int data)
{
  // Complete this method
    
    if(!head){
        head = new Node();
        head->data = data;
        head->next = NULL;
        return head;
    }
    
    Node* tmp = new Node();
    tmp = head;    
    while(tmp->next){
        tmp = tmp->next;               
    }
    
    tmp->next = new Node();
    tmp->next->data = data;
    tmp->next->next = NULL;
    
    return head;    
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
  int n1[] = {4,5,7,9,13,14};
  int n12[] = {1,1,1,1,1,1};
  int n2[] = {5,6,9,10,21};
  nod1 = NULL;
  nod2 = NULL;
  for(int i = 0; i < 6; i++){
    nod1 = Insert(nod1,n12[i]);
  }
  for(int i = 0; i < 4; i++){
    nod2 = Insert(nod2,n2[i]);
  }
	 
  
  readNode(nod1);
  std::cout << "\n";
  readNode(nod2);
  std::cout << "\n";
  nod1=MergeLists(nod1,nod2);
  readNode(nod1);
  std::cout << "\n";

	int nVal = GetNode(nod1,4);
  std::cout << nVal << " at position " << 4 << " from tail (tail is idx = 0) " << "\n";

	nod1 = RemoveDuplicates(nod1);
  readNode(nod1);
  std::cout << "\n";
  
  int mn = FindMergeNode(nod1,nod2);
  return 0;
}
