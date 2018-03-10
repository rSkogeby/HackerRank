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
#include <cassert>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
/*
mp - Map the key to the node in the linked list
cp - Capacity
tail - Double linked list tail pointer
head - Double linked list head pointer
set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
IN:

3 1
set 1 2
get 1
get 2

OUT:
2
-1
*/
class LRUCache : public Cache {
	private:
	
	protected:
	public:
		void set(int k,int val){
			Node *N;

			if(mp.empty()){
				N = new Node(k,val);
				tail = head = N;
				mp[k] = N;
			
				return;
			}
			auto iter = mp.find(k);

			if ( iter != mp.end() ) { //Cache hit 
				iter->second->value = val;

				//Change next and prev addresses
				if(head == iter->second) return; // is head

				iter->second->prev->next = iter->second->next;

				if(tail == iter->second) tail = tail->prev; // is tail
				else iter->second->next->prev = iter->second->prev;
				
				// Change iter to point to current head as next
				iter->second->next = head;
				// prev to Null
				iter->second->prev = NULL;
				head->prev = iter->second;
				head = iter->second;
			} else { // No cache hit
				N = new Node(head->prev,tail,k,val); 	
				head->prev = N;
				head = N;
				mp[k] = N;
				if(mp.size() > cp){
					tail = tail->prev;
					mp.erase(tail->next->key);
					delete tail->next;
					tail->next = NULL;

				}
			}
		}
		int get(int key){
			auto iter = mp.find(key);
			if(iter != mp.end()) return iter->second->value;

			return -1;
		}
		
		LRUCache(int&);
};
LRUCache::LRUCache(int &l){
	this->cp = l;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

