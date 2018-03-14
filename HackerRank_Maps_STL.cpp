#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int solve(istringstream &a);

int main(){

istringstream s(
"7"
" 1 Jesse 20"
" 1 Jess 12"
" 1 Jess 18"
" 3 Jess"
" 3 Jesse"
" 2 Jess"
" 3 Jess");
int sol = solve(s);
return 0;
}

int solve(istringstream &a) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	cin.rdbuf(a.rdbuf());
    map<string,int> m;
    int nQueries;
    cin >> nQueries;
    int type;
    string name;
    int mark;

    for(int i = 0; i < nQueries; i++){
        cin >> type;
        cin >> name;
        map<string,int>::iterator iter = m.find(name);
		
        switch(type){
            case 1:
        		cin >> mark;
				if (iter == m.end()){
                	m.insert(make_pair(name,mark));
				} else {
					iter->second += mark;
				}
                break;
            case 2:
				m.erase(iter);
                break;
            case 3:  
				cout << m[name] << endl;
				break; 
        }
    }
    return 0;
}
