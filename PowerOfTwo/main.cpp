#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if(n == 1){
    		return true;
    	}
        while(true){
        	if(n % 2 != 0){
        		return false;
        	}
        	if(n < 2){
        		return false;
        	}
        	if(n == 2){
        		return true;
        	}
        	n = n>>1;
        }
    }
};

int main(){
	Solution s;
	cout<<s.isPowerOfTwo(1)<<endl;
	return 0;
}