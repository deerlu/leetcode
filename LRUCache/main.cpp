#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
    	this->capacity = capacity;
    }
    
    int get(int key) {
    	auto it = keyMap.find(key);
        if(it != keyMap.end()){
        	keyList.push_back(key);
    		keyList.erase(it->second.first);
    		auto last = keyList.end();
        	it->second.first = --last;
        	return it->second.second;
        }else{
        	return -1;
        }
    }
    
    void set(int key, int value) {
    	auto it = keyMap.find(key);
    	if(it != keyMap.end()){
    		keyList.push_back(key);
    		keyList.erase(it->second.first);
    		auto last = keyList.end();
        	it->second = make_pair(--last,value);

    	}else if(keyList.size() == capacity){
        	keyList.push_back(key);
        	keyMap.erase(keyList.front());
        	keyList.pop_front();
        	auto last = keyList.end();
        	keyMap[key] = make_pair(--last,value);
        }else{
        	keyList.push_back(key);
        	auto last = keyList.end();
        	keyMap[key] = make_pair(--last,value);
        }
    }
private:
	list<int> keyList;
	unordered_map<int,pair<list<int>::iterator,int> > keyMap;
	int capacity;
};

int main(){
	LRUCache c(3);
	c.set(4,1);
	c.set(3,2);
	c.set(4,3);
	c.set(2,4);
	c.set(3,5);
	c.set(1,6);
	cout<<c.get(4)<<endl;
	return 0;
}