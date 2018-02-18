#include <vector>
#include <iostream>

// Maximum element
int main() {
  
  int N;
  std::cin >> N;
  
  std::vector <int> myStack;
  std::vector <int> maxVal;
  maxVal.push_back(0); // Only positive Vals
  
  while ( N-- ) {
  
    int type;
    std::cin >> type;
    
    if ( type == 1 ) {
      
      int val;
      std::cin >> val;
      myStack.push_back(val);
      if ( val >= maxVal.back() ) maxVal.push_back(val);
      
    } else if ( type == 2 ) {
      
      if ( myStack.back() == maxVal.back() ) maxVal.pop_back();
      myStack.pop_back();
      
    } else std::cout << maxVal.back() << std::endl;
  }
  return 0;
}

