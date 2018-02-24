#include <vector>
#include <stdio.h>

using namespace std;

void calcMaxEqualHeight(vector<int> v1,vector<int> v2,vector<int> v3){
  int i = v1.size() - 1;
  int j = v2.size() - 1;
  int k = v3.size() - 1;
  
  while ( i>=0 && j>=0 && k>=0 ){
    if( v1[i] == v2[j] && v2[j] == v3[k]){
      printf("%d",v1[i]);
      return;
    }
    while(v1[i] > v2[j] || v1[i] > v3[k]){
      i--;
    }
    while(v2[j] > v1[i] || v2[j] > v3[k]){
      j--;
    }
    while(v3[k] > v2[j] || v3[k] > v1[i]){
      k--;
    }
  }
  printf("0");
  return;
}

int main(){
  int n1;
  int n2;
  int n3;
  scanf("%d %d %d",&n1,&n2,&n3);
  vector<int> h1(n1);
  int tmp;
  for(auto h1_i = h1.rbegin(); h1_i < h1.rend(); ++h1_i){
    scanf("%d",&tmp);
    *h1_i = tmp;
  }
  vector<int> h2(n2);
  for(auto h2_i = h2.rbegin(); h2_i < h2.rend(); ++h2_i){
    scanf("%d",&tmp);
    *h2_i = tmp;
  }
  vector<int> h3(n3);
  for(auto h3_i = h3.rbegin(); h3_i < h3.rend(); ++h3_i){
    scanf("%d",&tmp);
    *h3_i = tmp;
  }
  
  
  int qtr = 1;
  for(auto v = std::next(h1.begin()); v < h1.end() ; ++v){
    h1[qtr] = h1[qtr-1]+*v;
    qtr++;
  } 
  qtr = 1;
  for(auto v = std::next(h2.begin()); v < h2.end() ; ++v){
    h2[qtr] = h2[qtr-1]+*v;
    qtr++;
  } 
  qtr = 1;
  for(auto v = std::next(h3.begin()); v < h3.end() ; ++v){
    h3[qtr] = h3[qtr-1]+*v;
    qtr++;
  } 
  calcMaxEqualHeight(h1,h2,h3);
  return 0;
}

