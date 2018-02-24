#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

void printStacks(std::vector<int> aa, std::vector<int> bb){
  for(auto v : aa){
    printf("%d ",v);		
  }
  printf("\n");		
  for(auto v : bb){
    printf("%d ",v);		
  }
  printf("\n");		
}

int main(){
  int g;
  std::cin >> g;
  for(int a0 = 0; a0 < g; a0++){
    int n;
    int m;
    int x;

    std::cin >> n >> m >> x;
		// STACK A
    std::vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       std::cin >> a[a_i];
    }
		// STACK B
    std::vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       std::cin >> b[b_i];
    }
		// CODE HERE
	  printStacks(a,b);	
    /*NAIVA SOLUTION*/
  if(false){ 
    int removed = 0;
    int _a = 0;
    int _b = 0;
    while( removed < x-a[_a] || removed < x-b[_b] ){
      if ( a[_a] < b[_b]  ) {
        removed += a[_a];
        _a++;
      } else {
        removed += b[_b];
        _b++;
      }
    }
  }
    int removed = 0;
    int _a = 0;
    while( removed <= x-a[_a] && _a < n ){
      removed += a[_a];
      _a++;
    }
    int count = _a;
    int _b = 0;
    while( _b < m && _a >= 0){
      removed += b[_b];
      _b++;
      while( removed > x && _a > 0 ){
        _a--;
        removed -= a[_a];
      }
      if( removed <= x && _a+_b > count ){
        count = _a + _b;
      }
    }
    printf("%d",count);
    printf("\n");
  }
  return EXIT_SUCCESS;
}
