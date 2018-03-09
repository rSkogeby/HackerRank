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

class SetupBoxes{
	private:
		int numBoxes;
		int interBoxDistance;
	public:
		void setNumBoxes(int n){ numBoxes = n; }
		void setInterBoxDistance(int d) { interBoxDistance = d; }
		int getSeparation(int Ma, int Mb){ 
			return abs(Ma-Mb); }
		SetupBoxes(int);
		SetupBoxes();
		~SetupBoxes();
};

SetupBoxes::SetupBoxes(int M){
	this->numBoxes = M;
	this->interBoxDistance = 1; // metres
}
SetupBoxes::SetupBoxes(){}
SetupBoxes::~SetupBoxes(){}

class Robot:public SetupBoxes{
	private:
		int robotOnePos;	
		int robotTwoPos;	
		int robotOneMov;
		int robotTwoMov;
	public:
		int initializeRobotPos(int p1, int p2) { 
			robotOnePos = p1;
			robotTwoPos = p2; 
		}
		void zeroMov(){
			robotOneMov = 0;
			robotTwoMov = 0;
		}
    	int moveNearestRobot(int Ma, int Mb);
		int printMovement(){
			cout << "Robot 1 moved " << robotOneMov << " meters" << endl;
			cout << "Robot 2 moved " << robotTwoMov << " meters" << endl;
		}
	Robot();
	~Robot();
};
Robot::Robot():
	SetupBoxes(){
		robotOneMov = 0;
		robotTwoMov = 0;
}
Robot::~Robot(){}
int Robot::moveNearestRobot(int Ma, int Mb){
	int d1 = abs(this->robotOnePos-Ma);
	int d2 = abs(this->robotTwoPos-Ma);
	if(getSeparation(this->robotOnePos,Ma) <= getSeparation(this->robotTwoPos,Ma)){
		this->robotOneMov += getSeparation(this->robotOnePos,Ma) + getSeparation(Ma,Mb);	
		cout << "one: " << this->robotOnePos << " to put candy from " << Ma << " to " << Mb <<", = "<< this->robotOneMov  <<endl;
		this->robotOnePos = Mb;
	} else {
		this->robotTwoMov += getSeparation(this->robotTwoPos,Ma) + getSeparation(Ma,Mb);
//		cout << d2 << " " << getSeparation(Ma,Mb) << endl;
		cout << "two: " << this->robotTwoPos << " to put candy from " << Ma << " to " << Mb <<", = "<< this->robotTwoMov  <<endl;
		this->robotTwoPos = Mb;
	}
	//cout << Ma << " -> "<< Mb << "  | one: " << this->robotOnePos << "  two: " << this->robotTwoPos << endl;
}


int solver(istringstream &s);


int main(){
	istringstream s(
	"3" // Number of test cases T
	" 5 4" // Test case 1: M=5 containers, N=4 queries
	" 1 5" // M(i=a) and M(i=b)
	" 3 2"
	" 4 1"
	" 2 4"
	" 4 2"	// Test case 2: M=4 containers, N=2 queries
	" 1 2"	
	" 4 3"
	" 10 3" // Test case 3: M=10 containers, N=3 queries
	" 2 4"  
	" 5 4"
	" 9 8");
	int out = solver(s);
}

int solver(istringstream &s){
	cin.rdbuf(s.rdbuf());
	/*
		M containers w. inf candies
		Arranged in single row
		d(M(i+1)-M(i))=1 m
		2 robots
		Pick up 1 piece of candy and transport it between any two containers
		Queries: From M(i=a) to M(i=b)
		Executes N queries in total
		T test cases
	*/
	
	int T,M,N,Ma,Mb,MaOne,MbOne,MaTwo,MbTwo;
	cin >> T;
	Robot robots;
	for(int j = 0; j < T; j++){
		cin >> M >> N;
		robots.setNumBoxes(M);
		robots.zeroMov();
		cin >> MaOne >> MbOne;
		cin >> MaTwo >> MbTwo;
		robots.initializeRobotPos(MaOne,MaTwo);
//		robots.moveNearestRobot(MaOne,MbOne);
//		robots.moveNearestRobot(MaTwo,MbTwo);
		for(int i = 0; i < N-2; i++){
			cin >> Ma >> Mb;
			robots.moveNearestRobot(Ma,Mb);
		}
			robots.printMovement();
	}
	string x = "abc";
	string y = "abc";
	cout << x.compare(y) << endl;
	return 0;
}

