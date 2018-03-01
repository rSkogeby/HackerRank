#include<iostream>

int main() {
  int T;
  int N;
  int K;
  int max = 0;
  std::cin >> T;

  for( int i = 0; i < T; i++ ) { 
    std::cin >> N >> K;
    for( int j = 1; j < N; j++ ) { 
      for( int k = 1; k <= N-j; k++){
        int AND = j&(j+k);
        if ( AND < K && max < AND ) max = AND;
      }  
    }   
    std::cout << max << std::endl;
    max = 0;
  }
  return 0;
}
