#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

double median(const vector<int>::iterator& startIndex,const vector<int>::iterator& endIndex){
    int vecLength = endIndex-startIndex;
    double mdian;
    if(vecLength%2 == 1){ 
        mdian = (double) *(startIndex+(vecLength-1)/2);
    } else {
        mdian = (double) (*(startIndex+vecLength/2-1)+*(startIndex+vecLength/2))/2;
    }   
    return mdian; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nValues, tmpVal;
    cin >> nValues;
    map<int,int> value_map;
    vector<int> values(nValues);
    vector<int> frequencies(nValues);
    int finalVectorLength=0;
    for(int i = 0; i < 2*nValues; i++){
        cin >> tmpVal;
        if(i < nValues) {
            values[i] = tmpVal;
            value_map[tmpVal];
        } else {
            value_map[values[i-nValues]] = tmpVal;
        }
    }   
    vector<int> fullRange;
    for (auto [val,freq] : value_map){
        for ( int i = 0; i < freq ; i++){
            fullRange.push_back(val);
        }
    }
    
    double Q1, Q2, Q3; 
    Q2 = median(fullRange.begin(),fullRange.end());
    if(fullRange.size()%2 == 1){ 
        Q1 = median(fullRange.begin(),fullRange.begin()+(fullRange.size()-1)/2);   
        Q3 = median(fullRange.end()-(fullRange.size()-1)/2,fullRange.end());   
    } else {
        Q1 = median(fullRange.begin(),fullRange.begin()+(fullRange.size())/2); 
        Q3 = median(fullRange.end()-(fullRange.size())/2,fullRange.end()); 

    }   
    cout << fixed << setprecision(1);
    cout <<  Q3-Q1 << endl;
    
    return 0;
}

