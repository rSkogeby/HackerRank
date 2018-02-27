#include <iostream>
#include <stdlib.h>

struct Node{
  int data;
  Node* parent;
  Node* right;
  Node* left;
};

int main(){
  int N;
  int M;
  //Node* root;
  int root
  std::cin >> N >> M >> root;
  int edgeFrom;
  int edgeTo;
  // Get edges
  for ( int i = 0; i < N-1; i++ ){
    std::cin >> edgeFrom >> edgeTo;
  }
  // Get color values
  int color;
  for ( int i = 0; i < N-1; i++ ){
    std::cin >> color; 
    insertColor
  }



/*
  Tree
  N colored nodes
  color is integer in 1,1e9
  find distinct colors (unique node values) in subtree rooted at s

You are given a tree with N nodes with every node being colored. A color is represented by an integer ranging from 1 to 109. Can you find the number of distinct colors available in a subtree rooted at the node s?

Input Format
The first line contains three space separated integers representing the number of nodes in the tree (N), number of queries to answer (M) and the root of the tree.

In each of the next N-1 lines, there are two space separated integers(a b) representing an edge from node a to Node b and vice-versa.

N lines follow: N+ith line contains the color of the ith node.

M lines follow: Each line containg a single integer s.

Output Format
Output exactly M lines, each line containing the output of the ith query.
*/
