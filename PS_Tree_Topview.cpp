#include <iostream>
#include <queue>
#include <stack>

void topView(node * root) {
// Returns topview: 
/*
              4
             / \
            3   5
           / \
          1   2

Topview is read left to right. Internal nodes are ignored. 
In this case topview is 1-3-4-5.

*/
  if(!root) return;
  node* rPtr = root;
  std::stack<int> left;
  while (root->left){
    root = root->left;
    left.push(root->data);
  }
  root = rPtr;
  std::queue<int> right;
  while (root->right){
    right.push(root->data);
    root = root->right;
  }
  right.push(root->data);
  
  while (!left.empty()) {
    std::cout << left.top() << " ";
    left.pop();
  }
  while (!right.empty()) {
    std::cout << right.front() << " ";
    right.pop();
  } 
  
}
