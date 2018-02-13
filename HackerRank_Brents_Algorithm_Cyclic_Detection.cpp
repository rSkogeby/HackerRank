#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

typedef unsigned long ULONG;
static ULONG N,S,P,Q;
const static ULONG pow2 = (ULONG) pow(2,31);
ULONG f(ULONG x){ return ( (x*P + Q) % pow2 );  }

ULONG BrentsAlgorithm(const ULONG x0){
	ULONG power = 1;
	ULONG n = 0; // mu
	ULONG m = 1; // lambda
	ULONG tortoise = x0;
	ULONG hare = f(x0);

	// Find some repitition 
	while(tortoise != hare){
		if( power == m ){
			tortoise = hare;
			power *= 2;
			m = 0;
		}
		if( m >= N ){
			break;
		}
		m++;
		hare = f(hare);
	}
	
	// Position of first repetion of length equal to period m
	tortoise = hare = x0;
	for (ULONG i = 0; i < m; i++){
		hare = f(hare);
	}
	// Hare and tortoise m apart here

	// Move tortoise and hare equally fast to find first repetition with period m
	while(tortoise != hare){
		tortoise = f(tortoise);
		hare = f(hare);
		n++;
		if ( n == N ) return N;
	}
	return m;

	
}


int main(){
	ULONG x0;
	cin >> N >> S >> P >> Q;
	cout << BrentsAlgorithm(S) << endl;
	return 0;
}
