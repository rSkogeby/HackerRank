#include <iostream>


struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* setChildren(Node*,int,int); 
Node* newNode(int); 
Node* buildTree(Node*,int,int,int); 


int main(){
  /*
  N nodes 
  N lines follow
  a b (a idx of left, b idx of right of ith node)
  -1 is null node
  T
  T lines follow with int K

  For each K perform swap and print inorder traversal of whole tree
  Level order traversal indexing

  Sample output:
  2 9 6 4 1 3 7 5 11 8 10
  2 6 9 4 1 3 7 5 10 8 11
  */
  int numNodes;
  std::cin >> numNodes;
  
  int idxLeft,idxRight;
  Node* root = NULL;
  for( int i = 0; i < numNodes; i++ ){
    std::cin >> idxLeft >> idxRight;
    root = buildTree(root,idxLeft,idxRight,i+1);
  }


  return 0;
}

// SETCHILDREN
Node* setChildren(Node* node,int iL, int iR){
  if(iL >= 0){
    if(!node->left){
      node->left = newNode(iL);
    } else {
      node->left->data = iL;
    }
  } 
  if(iR >= 0){
    if(!node->right){
      node->right = newNode(iR);
    } else {
      node->right->data = iR;
    }
  }
  return node;
}

// NEWNODE
Node* newNode(int idx){
  Node* node = new Node();
  node->data = idx; 
  node->left = NULL;
  node->right = NULL;
  return node;
}

// LEVELORDERINSERT
Node* buildTree(Node* root,int iL,int iR, int idx){
  if( !root && idx == 1 ){
    root = newNode(idx);
    root = setChildren(root, iL,iR);
    return root;
  }
  
  
  Node* rPtr = root;
  while( root ){
    root = root->left; 
  }

  return rPtr;
}
