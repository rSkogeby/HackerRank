#include <iostream>

// Finds lowest common ancestor of BST
node *lca(node *root, int v1,int v2)
{
  if(!root) return root; 
  
  if( v1<root->data && v2 < root->data ) root = lca(root->left,v1,v2);
  if( v1>root->data && v2 > root->data ) root = lca(root->right,v1,v2);
  
  return root;
   
}
