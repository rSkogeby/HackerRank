// Snippet to measure the execution time
#include <time.h>
#include <iostream>

using namespace std;

int main(){
	
	clock_t sstart, _end;
	double cpu_time_used;
	sstart = clock();
	
	// Function call begin
	

	// Function call end

	_end = clock();
	cout << "start time: " << sstart << endl;;
	cout << "end time: " << _end << endl;
	cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
	cout << "Time in s: " << (double) (_end-sstart)/CLOCKS_PER_SEC*1000 << " ms " <<endl;

	return 0;
}
