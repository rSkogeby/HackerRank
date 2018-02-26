#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

struct stringCollection{
  std::vector<std::string> contains;
};
struct queryCollection : stringCollection{
  std::map<std::string,int> count;
};
struct IQ{
  stringCollection* input;
  queryCollection* queries;
};


IQ readInput(){
  int N;
  stringCollection* input = new stringCollection();
  queryCollection* queries = new queryCollection();

  std::string tmp;
  std::cin >> N;
  std::cin.ignore();
  for( int n = 0; n < N; n++){
    std::cin >> tmp;
    input->contains.push_back(tmp);
  }


  int Q;
  std::cin >> Q;
  std::cin.ignore();
  for( int q = 0; q < Q; q++){
    std::cin >> tmp;
    queries->contains.push_back(tmp);
  }
  IQ rtrn;
  rtrn.input = input;
  rtrn.queries = queries;
  return rtrn;
}

void compareQuery(IQ iq){
 
  for(auto qq : iq.queries->contains){
    if(iq.queries->count.count(qq) == 0){
      for(auto ii : iq.input->contains){
        if(qq == ii){
            iq.queries->count[qq]++; 
        }
      }
    }
  }
}

int main(){
  IQ iq = readInput();
  compareQuery(iq);
  for (auto cc : iq.queries->contains){
    std::cout << iq.queries->count[cc] << std::endl;
  }
  delete iq.input;
  delete iq.queries;
  return EXIT_SUCCESS;
}
  /*
  INPUT:
  N
  s1
  s2
  .
  .
  .
  sN
  Q
  q1
  .
  .
  .
  qQ

  */
