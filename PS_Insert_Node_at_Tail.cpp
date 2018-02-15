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
    cout << head->data << " ";
    readNode(head->next);
  }
}

int main(){
  
  Node* hd = new Node();
  Node* nod1 = new Node();
  Node* nod2 = new Node();
  Node* nod3 = new Node();
  int d = 3;
  hd = NULL;
  hd = Insert(hd,d);
  hd = Insert(hd,1);
  hd = Insert(hd,2);
  hd = Insert(hd,4);
  
  
  readNode(hd);
  cout << "\n";
  return 0;
}
