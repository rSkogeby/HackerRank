#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){

  deque<int> slidingWindow(k);

  for(int i = 0; i < k; ++i){
  
    // If arr[i] is beq than end of queue, remove end  
    while( !slidingWindow.empty() && arr[i] >= arr[slidingWindow.back()] ){
      slidingWindow.pop_back();
    }
    // Store index to max array value
    slidingWindow.push_back(i);
  }
  for (int i = k; i < n; i++){
    
    // Front of queue contains largest element index
    printf("%d ",arr[slidingWindow.front()]);

    // Remove elements outside window 
    while( !slidingWindow.empty() && slidingWindow.front() <= i-k ){

      slidingWindow.pop_front();

    }
    
    // If arr[i] is beq than end of queue, remove end  
    while( !slidingWindow.empty() && arr[i] >= arr[slidingWindow.back()] ){

      slidingWindow.pop_back();

    }

    slidingWindow.push_back(i);

  }

  printf("%d\n",arr[slidingWindow.front()]);

}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       scanf("%d %d",&n,&k);
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}

