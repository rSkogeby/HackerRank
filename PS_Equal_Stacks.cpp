#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

class Cylinder{
  private:
    int height;

  public:
    void setHeight(int h){
      height = h;
    }
    int getHeight(){
      return height;
    }
};

class CylinderStack : public Cylinder {
  private:
    int numberCylinders;
    std::vector<Cylinder> cylinders;

  public:
    int getTopCylinderHeight(){
      int topHeight = cylinders.back().getHeight();
      return topHeight;
    }
    int getStackHeight(){
      int totHeight = 0;
      for( auto v : cylinders){
        totHeight += v.getHeight();
      }
      return totHeight;
    }
    std::vector<Cylinder> getCylinders(){
      return cylinders;
    }
    int getNCylinders(){
      return numberCylinders;
    }
    void fillCylinderStackNew(int h){
      Cylinder c;
      c.setHeight(h);
      cylinders.push_back(c);
      numberCylinders++;
    }
    void fillCylinderStack(Cylinder c){
      cylinders.push_back(c);
      numberCylinders++;
    }
    void drawCylinderStack(){
       std::cout << "\n";
      for( auto v : cylinders){
        for( int i = 0; i < v.getHeight(); i++){
          if( v.getHeight() > 1 ){
            if( i == 0 ) std::cout << "[";
            else if( i == v.getHeight()-1 ) std::cout << "]";
            else std::cout << "\u039E";
          } else {
            std::cout << "\u039E";
          }
        }
      }
       std::cout << "\n";
       std::cout << "\n";
    }
    void pop(){
      cylinders.pop_back();
      numberCylinders--;
    }
    CylinderStack();
    ~CylinderStack();
};

CylinderStack::CylinderStack() : 
  Cylinder(){
  this->numberCylinders = 0;  
}
CylinderStack::~CylinderStack(){}

void removeTop(CylinderStack* s){
  if(s->getNCylinders() > 0)  s->pop();
}

void makeStacksEqualHeight(CylinderStack* s1, CylinderStack* s2, CylinderStack* s3){
  
  while(s1->getStackHeight() != s2->getStackHeight() &&
        s1->getStackHeight() != s3->getStackHeight()){
    
    if(s1->getTopCylinderHeight() < s2->getTopCylinderHeight() &&
       s1->getTopCylinderHeight() < s3->getTopCylinderHeight()){
      removeTop(s1);  
    }
    else if(s2->getTopCylinderHeight() < s1->getTopCylinderHeight() &&
       s2->getTopCylinderHeight() < s3->getTopCylinderHeight()){
      removeTop(s2);  
    } else removeTop(s3);
    //else if(s3->getTopCylinderHeight() < s1->getTopCylinderHeight() &&
    //   s3->getTopCylinderHeight() < s2->getTopCylinderHeight()){
    //  removeTop(s3);  
    //}
    


    std::cin.get(); 
    s1->drawCylinderStack(); 
    s2->drawCylinderStack(); 
    s3->drawCylinderStack(); 
  } 
}

void calcMaxEqualHeight(CylinderStack* s1, CylinderStack* s2, CylinderStack* s3){
  std::vector<Cylinder> v1 = s1->getCylinders(); 
  std::vector<Cylinder> v2 = s2->getCylinders();
  std::vector<Cylinder> v3 = s3->getCylinders(); 
  std::vector<int> t1; 
  std::vector<int> t2;
  std::vector<int> t3;
  std::vector<int> cum1; 
  std::vector<int> cum2;
  std::vector<int> cum3;

 // Fill vectors of heights 
  for ( auto ve1 : v1 ) {
    t1.push_back(ve1.getHeight());
  }
  for ( auto ve2 : v2 ) {
    t2.push_back(ve2.getHeight());
  }
  for ( auto ve3 : v3 ) {
    t3.push_back(ve3.getHeight());
  }
 
 // Calc cumulative heights
  int prev = 0;
  for( auto te1 : t1 ){
    te1 += prev;
    prev = te1;
    cum1.push_back(te1);
    std::cout << te1 << " ";
  }
    std::cout << "\n";
  prev = 0;
  for( auto te2 : t2 ){
    te2 += prev;
    prev = te2;
    cum2.push_back(te2);
    std::cout << te2 << " ";
  }
    std::cout << "\n";
  prev = 0;
  for( auto te3 : t3 ){
    te3 += prev;
    prev = te3;
    cum3.push_back(te3);
    std::cout << te3 << " ";
  }
  std::cout << "\n";

  // Find largest equal number (LEN) in cum. heights
  bool out = false;
  int largestEqualIdx[3];
  for( std::vector<int>::iterator te1 = cum1.begin(); te1 < cum1.end(); ++te1 ){
    for( std::vector<int>::iterator te2 = cum2.begin(); te2 < cum2.end(); ++te2 ){
      if ( *te1 == *te2 ) {
        for( std::vector<int>::iterator te3 = cum3.begin(); te3 < cum3.end(); ++te3 ){
          if( *te1 == *te3 ){
            largestEqualIdx[0] = te1-cum1.begin();
            largestEqualIdx[1] = te2-cum2.begin();
            largestEqualIdx[2] = te3-cum3.begin();
            std::cout << *te1 << " " << "\n";
            out = true;
            break;
          }
        }
      }
    if(out) break;
    }
    out = false;
  }

  // Calculate total number of cylinders to remove to reach 
  // index of LEN in all stacks
  int numCyl = cum1.size()-largestEqualIdx[0]-1;
  numCyl +=    cum2.size()-largestEqualIdx[1]-1;
  numCyl +=    cum3.size()-largestEqualIdx[2]-1;

  std::cout << cum1[largestEqualIdx[0]] << std::endl; 
 //std::cout << numCyl << std::endl; 
    
}

int main(){
  CylinderStack* STACK_ONE = new CylinderStack();
  CylinderStack* STACK_TWO = new CylinderStack();
  CylinderStack* STACK_THREE = new CylinderStack();
  int h1[] = {3,2,5,6,2,3,2,4}; 
  int h2[] = {1,1,4,5,4,2,1,2}; 
  int h3[] = {4,5,1,1,4,3,2,1};
  
  
   
  
  int cylHeight;
  int numCyls = 8;
  srand (time(NULL)); // initialize random seed
  //for ( int i = 0; i < numCyls; i++){
  //   cylHeight = rand() % 10 + 1;
  //   STACK_ONE->fillCylinderStackNew(cylHeight);
  //   cylHeight = rand() % 10 + 1;
  //   STACK_TWO->fillCylinderStackNew(cylHeight);
  //   cylHeight = rand() % 10 + 1;
  //   STACK_THREE->fillCylinderStackNew(cylHeight);

  //}
  for ( int i = 0; i < numCyls; i++){
     STACK_ONE->fillCylinderStackNew  (h1[i]);
     STACK_TWO->fillCylinderStackNew  (h2[i]);
     STACK_THREE->fillCylinderStackNew(h3[i]);
  }

  STACK_ONE->drawCylinderStack();
  STACK_TWO->drawCylinderStack();
  STACK_THREE->drawCylinderStack();

  //while(STACK_ONE->getStackHeight() != STACK_TWO->getStackHeight() &&
  //      STACK_ONE->getStackHeight() != STACK_THREE->getStackHeight()){
  //  
  //} 
 // makeStacksEqualHeight(STACK_ONE,STACK_TWO,STACK_THREE);
  calcMaxEqualHeight(STACK_ONE,STACK_TWO,STACK_THREE);
  delete STACK_ONE;
  delete STACK_TWO;
  delete STACK_THREE;
  return EXIT_SUCCESS;
}


/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height. 
*/

