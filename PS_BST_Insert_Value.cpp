#include <iostream>

node * insert(node * root, int value) {
// Insert node in an ordered binary search tree  
  if(!root){
    root = new node();
    root->left = NULL;
    root->right = NULL;
    root->data = value;
    return root; 
  } else if(root->data > value){
    root->left = insert(root->left,value);
  } else if (root->data < value) {
    root->right = insert(root->right,value);
  }

   return root;
}
