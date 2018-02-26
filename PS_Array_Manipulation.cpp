#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

void printVec(long int* vec,int n){
  for(int i = 0; i < n; i++) {
    std::cout << vec[i] << std::endl;
  }
}
void findMax(std::vector<int> vec){
  auto mel = max_element(vec.begin(),vec.end());
  std::cout << *mel << std::endl;
}

int main(){
  long int n;
  std::cin >> n; // size of array
  long int m;
  std::cin >> m; // number of operations
//  std::vector<int> vec(n,0);
  long int *vec = new long int[n+1]();
  long int a; // interval start
  long int b; // interval end
  long int val;
  for(int i = 0; i < m; i++){
    std::cin >> a >> b >> val;
    vec[a] += val;
    if( b < n ) vec[b+1] -= val;
  }
//  printVec(vec,n);
  long int x = 0;
  long int max = 0;
  for(int i = 1; i <= n; i++){
    x = x + vec[i];
    if(max < x) max = x;
  }
  std::cout << max << std::endl;

  //findMax(vec);
  return EXIT_SUCCESS;
}

/*
1-indexed list of size n init with 0
m operation on the list
output max final values of all n elements in list
for every operation: ints a b and k.
  add k to all elements in inclusive range a,b
  lsit numbered from 1 to n
*/


