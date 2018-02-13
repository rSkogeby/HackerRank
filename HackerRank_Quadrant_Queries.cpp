#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Plane{
    private:
        vector<vector<int> > points;
    public:
        void fillPlane(int n){ 
            vector<int> point(2,0);
            for(int k = 0; k < n; k++){
                cin >> point[0] >> point[1];
                points.push_back(point);
            }
        }
        vector<vector<int> > getPlane(){
            return points;
        }
        void mirrorX(int i,int j){
            for(int k = i-1; k < j; k++){
                points[k][1] *= -1;
            }
        }
        void mirrorY(int i,int j){
            for(int k = i-1; k < j; k++){
                points[k][0] *= -1;
            }
        }
        void pointsPerQuadrant(int i, int j){
            vector<int> ppQ(4,0);
            for(int k = i-1; k < j; k++){
                if(points[k][0] > 0){ 
                    if(points[k][1] > 0){
                        // Quadrant 1
                        ppQ[0]++;
                    } else {
                        // Quadrant 4
                        ppQ[3]++;
                    }
                } else if(points[k][0] < 0){
                    if(points[k][1] > 0){
                        // Quadrant 2
                        ppQ[1]++;
                    } else {
                        // Quadrant 3
                        ppQ[2]++;
                    }
                }
            }
            cout << ppQ[0] << " " << ppQ[1] << " " << ppQ[2] << " " << ppQ[3] << endl;
        }
};
int main(){
int n;
    int x,y,i,j,q;
    char type;
    vector<int> p2;
    Plane flatland;
    cin >> n;
    flatland.fillPlane(n);
    cin >> q;
    for(int l = 0; l < q; l++){
        cin >> type >> i >> j;
        switch(type){
            case 'X':
                flatland.mirrorX(i,j);
                break;
            case 'Y':
                flatland.mirrorY(i,j);
                break;
            case 'C':
                flatland.pointsPerQuadrant(i,j);
                break;
            default:
                cout << "Default called in switch" << endl;
        }
    }
    return 0;
}
