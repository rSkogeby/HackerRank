#include <iostream>

void inOrder(node *root) {
  // Inorder: Left Root Right
  
  if(!root) return;
  
  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);
  
}
