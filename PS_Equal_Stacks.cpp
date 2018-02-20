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
    std::vector<Cylinder> getCylinders(){
      return cylinders;
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
     
  for ( auto ve1 : v1 ) {
    v1.push_back(ve1.getHeight());
  }
  for ( auto ve2 : v2 ) {
    v2.push_back(ve2.getHeight());
  }
  for ( auto ve3 : v3 ) {
    v3.push_back(ve3.getHeight());
  }

}

int main(){
  CylinderStack* STACK_ONE = new CylinderStack();
  CylinderStack* STACK_TWO = new CylinderStack();
  CylinderStack* STACK_THREE = new CylinderStack();
  
  int cylHeight;
  int numCyls = 10;
  srand (time(NULL)); // initialize random seed
  for ( int i = 0; i < numCyls; i++){
     cylHeight = rand() % 10 + 1;
     STACK_ONE->fillCylinderStackNew(cylHeight);
     cylHeight = rand() % 10 + 1;
     STACK_TWO->fillCylinderStackNew(cylHeight);
     cylHeight = rand() % 10 + 1;
     STACK_THREE->fillCylinderStackNew(cylHeight);

  }

  STACK_ONE->drawCylinderStack();
  STACK_TWO->drawCylinderStack();
  STACK_THREE->drawCylinderStack();

  //while(STACK_ONE->getStackHeight() != STACK_TWO->getStackHeight() &&
  //      STACK_ONE->getStackHeight() != STACK_THREE->getStackHeight()){
  //  
  //} 
  makeStacksEqualHeight(STACK_ONE,STACK_TWO,STACK_THREE);
  delete STACK_ONE;
  delete STACK_TWO;
  delete STACK_THREE;
  return EXIT_SUCCESS;
}


/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height. 
*/

