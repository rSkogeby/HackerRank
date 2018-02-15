#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Wheel{
  private:
    vector<int> numbers;
  public:
    void readNumbers(int n,int d){
      int num;
      vector<int> nn(n);
      for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if(i-d < 0) nn[n+(i-d)] = num;
        else nn[i-d] = num;
      }
      numbers = nn;
    }
    vector<int> retVec(){
      return numbers;
    }
};

// This is too slow:
//void Wheel::leftRotate(int d){
//  int tmp;
//  int idx;
//  while( d > 0 ){
//    for( int i = 0; i < this->numbers.size()-1 ; i++){
//      swap(this->numbers[i],this->numbers[i+1]);
//    }
//  d--;
//  }
//}



int main(){
  int n,d; // n integers, d left rotations
  scanf("%d %d",&n,&d);
  Wheel ferris;
  ferris.readNumbers(n,d);
  for(auto v : ferris.retVec()){
    printf("%d ", v);;
  }
  printf("\n");;

}
