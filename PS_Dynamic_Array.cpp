#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    cin >> N >> Q;
  vector<int> lst(0);
    vector<vector<int>> seqList(N,lst);
    int lastAnswer = 0;
    int x,y,type;
  int idxInVec;
  int idxInList;
    for(int i = 0; i < Q;i++){
        cin >> type >> x >> y;
        //cout << type << " " << x << " " << y << endl;
        if(type == 1) {
      //cout << "(" << x << "^" << lastAnswer << ") % " << N << " Full: " << (x^lastAnswer) % N << endl;
          idxInVec = (x^lastAnswer) % N;
      seqList[idxInVec].push_back(y);

    } else if (type == 2){
      //cout << "(" << x << "^" << lastAnswer << ") % " << N << " Full: " << (x^lastAnswer) % N << endl;
      idxInVec = (x^lastAnswer) % N;
      idxInList = y % seqList[idxInVec].size();
      lastAnswer = seqList[idxInVec][idxInList];
      cout << lastAnswer << "\n";
    }
    }
    
    return 0;
}
