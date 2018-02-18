#include <cmath>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::priority_queue<int, std::vector<int>, std::greater<int> > prio_q;

prio_q* combineCookies(prio_q* pq,int K){
  int count = 0;
  while( true ){
    if(pq->top() < K){
      int x = 1*pq->top();
      pq->pop(); 
          
      if(pq->empty()) {
        std::cout << -1;
        break;
      }
          
      int y = 2*pq->top();
      pq->pop(); 

      pq->push(x+y);

      count++;
    } else {
      std::cout << count << std::endl;
      break;
    }     
  }
  return pq;
}

int main(){
  int N; // number
  int K; // Desired sweetness
  prio_q ppq;
  std::cin >> N >> K;
  int value;
  for ( int i = 0; i < N; i++ ){
    std::cin >> value; 
    ppq.push(value); 
  }
  prio_q* hPtr = &ppq;
  hPtr = combineCookies(hPtr,K);

    return 0;
}
