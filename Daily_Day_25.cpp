#include <stdlib.h>
#include <iostream>
#include <string>

/*
  11
  2 3 4 5 6 7 8 9 10
    3   5   7   9

  31  
    3   5   7   9   11   13   15   17   19   21   23   25   27   29   31
    3   5   7   3*3 11   13   3*5  17   19   3*7  23   5*5  3*9  29   31

           1  2   3    4  5   6   7  8  9 
    6k-1 = 5  11  17  23  29
    6k+1 = 7  13  19  25  31

*/

void isPrime(int val){
  std::string primeCheck = "";
  int k; 
  int oddNum;
	if( val < 5){ 
    if ( val == 1 ){
      primeCheck = "Not prime";
    } else if ( val == 2  ) { 
      primeCheck = "Prime";
    } else if ( val == 3  ) { 
      primeCheck = "Prime";
    } else {
      primeCheck = "Not prime";
    }
  } else if ( val % 2 == 0  ) { 
      primeCheck = "Not prime";
  } else if ( val % 3 == 0  ) { 
      primeCheck = "Not prime";
  } else {
    for( int i = 1; k*k < val; i++  ){
      for( int j = -1; j < 2; j = j+2 ){
        k = 6*i + j;
        if( val % k == 0 && val != k ){ // Breaks on O(1) for even numbers
          // is not prime
          primeCheck = "Not prime";
          break;
        }
      }
      if( primeCheck == "Not prime" ) break;
    }
    if( primeCheck == "" ) primeCheck = "Prime";
  }
  std::cout << primeCheck << std::endl;
}

int main(){

  int N;
  std::cin >> N;
  int INP;
  
  for( int i = 0; i < N; i++ ){
    std::cin >> INP;
    isPrime(INP);
  }
  return EXIT_SUCCESS;
}
