#include <iostream>


void decode_huff(node * root,string s)
{
  node* curr = root;
  for(auto c : s){
    curr = c == '0' ? curr->left : curr->right;
    if(curr->data) {
      std::cout << curr->data;
      curr = root;
    }
  }
}

/*
Huffman coding assigns variable length codewords to fixed length input characters based on their frequencies. More frequent characters are assigned shorter codewords and less frequent characters are assigned longer codewords. A Huffman tree is made for the input string and characters are decoded based on their position in the tree. We add a '0' to the codeword when we move left in the binary tree and a '1' when we move right in the binary tree. We assign codes to the leaf nodes which represent the input characters.
*/
