#include <vector>
#include <iostream>
#include <functional>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > trackAdd;
std::priority_queue<int, std::vector<int>, std::greater<int> > trackRemove;

void add(){
  int n;
  std::cin >> n;
  trackAdd.push(n);
}

void remove(){
  int n;
  std::cin >> n;
  trackRemove.push(n);
}

void printMin(){
  while( !trackRemove.empty() && trackRemove.top() == trackAdd.top() ){
    trackAdd.pop();
    trackRemove.pop();
  }
  std::cout << trackAdd.top() << std::endl;
}

int main() {
  int queries;
  std::cin >> queries;
  int type;
  for (int i = 0; i < queries; i++){
    std::cin >> type;
    if( type == 1) add();
    else if( type == 2) remove();
    else if( type == 3) printMin();
  }
  return 0;
}
