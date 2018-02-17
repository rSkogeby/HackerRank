#include <iostream>

void preOrder(node *root) {
//Preorder traversal of a binary tree given root.
  
  if(!root) return;
  
  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);

}
