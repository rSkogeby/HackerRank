#include <iostream>

void postOrder(node *root) {
  // Postorder : left right root traversal
  
  if(!root) return;
  
  postOrder(root->left);
  postOrder(root->right);
  std::cout << root->data << " ";

}
