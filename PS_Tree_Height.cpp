#include <iostream>

int height(Node* root) {
  // Returns height of binary tree.
  if(!root) return -1;
  
  int l = 1+height(root->left);
  int r = 1+height(root->right);
  
  return l > r ? l : r;
  
}
