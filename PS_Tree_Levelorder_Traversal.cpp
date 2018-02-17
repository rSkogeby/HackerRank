#include <iostream>
#include <queue>

void levelOrder(node * root) {
	// Prints each level sequentially from left to right. Starting at L 0.   
  if(!root) return;
  
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    cout << q.front()->data << " ";
    if(q.front()->left) q.push(q.front()->left);
    if(q.front()->right) q.push(q.front()->right);
    q.pop();
  }
}
