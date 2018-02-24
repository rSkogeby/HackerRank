#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
typedef std::priority_queue<int> PQ;
long largestRectangle(std::vector <int> h) {
  /*
  1. First rectangle:
         __
   __   |  |
  |  |__|  |
  |  |  |  |__
  |  |  |  |  |

  */
  PQ area;
  int a_tmp;
  int i,j;
  int last = 0;
  int height = 0;
  std::vector<int> isActive(h.size(),0);
  std::cout << h.size() << std::endl;
  for ( int i = 0; i < h.size(); i++){
    for( int j = 0; j < i; j++ ){
      if( h[i] > h[j] ){      
        isActive[j] = i;        
      }
    }
  }
    area.push(i); 
      for (int k = 0; k < h.size() ; k++) {
        if( isActive[k] == 0 ) std::cout << h[k] << " is active until " << isActive[k] << std::endl;
        else std::cout << h[k] << " is active until " << h[isActive[k]] << std::endl;
      }
  return 1;

}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       std::cin >> h[h_i];
    }
    long result = largestRectangle(h);
    std::cout << result << std::endl;
    return 0;
}

