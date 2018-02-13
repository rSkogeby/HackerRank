#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <bitset>
using namespace std;

const unsigned int N = 10000001;

struct Workshop{
	int startTime;
	int duration;
	int endTime;
};

struct Available_Workshops{
	int n;
	Workshop* arr = new Workshop[N];
};

Available_Workshops* initialize(int startTime[], int duration[], int n){
	Available_Workshops* ws = new Available_Workshops();
	ws->n = n;
	for (int i = 0 ; i < n; i++){
		ws->arr[i].startTime = startTime[i];
		ws->arr[i].duration = duration[i];
		ws->arr[i].endTime = startTime[i]+duration[i];
	}
	return ws;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
	int maxNWorkshops=0;
	int n = ptr->n;
	vector<int> T(2);
	vector<vector<int> > workshops;
	for ( int i = 0; i < n; i++){
		T[0] = ptr->arr[i].endTime;
		T[1] = ptr->arr[i].startTime;
		workshops.push_back(T);
	}
	sort(workshops.begin(),workshops.end(),[]( vector<int> lhs, vector<int> rhs){return lhs[0]<rhs[0]; } );
	int current_End = 0;
	int current_Start = 0;

	for ( int i = 0; i < n; i++){
		if( current_Start < workshops[i][0] && current_End > workshops[i][1] ){
			continue;
		} else {
			current_End = workshops[i][0];
			current_Start = workshops[i][1];
			maxNWorkshops++;
		}

			
	}
	return maxNWorkshops;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }
    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
