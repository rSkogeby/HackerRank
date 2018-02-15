#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* push_front(Node *head,int data)
{
  // Complete this method
    Node* tmp = new Node();
    tmp->next = head;    
    tmp->data = data;

    return tmp;    
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
  hd = push_front(hd,d);
  hd = push_front(hd,1);
  hd = push_front(hd,2);
  hd = push_front(hd,4);
  
  
  readNode(hd);
  cout << "\n";
 
  deleteNodes(hd); 
  return 0;
}
