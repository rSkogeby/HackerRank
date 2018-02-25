#include <iostream>

string kangaroo(int x1, int v1, int x2, int v2) {
    // Complete this function
  double xx = (double) (x2-x1)/(v1-v2);
  if( xx > 0 ){ 
    if( ((double) xx-((int) xx)) > 0){
      return "NO";
    } else {
      return "YES";
    }
  } else {
    return "NO";
  }
}

int main() {
    int x1;
    int v1;
    int x2;
    int v2;
    std::cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    std::cout << result << std::endl;
    return 0;
}

