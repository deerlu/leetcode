#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
    	int result = 0;
        for(int i = 1; i * i <= n; i++){
        	result++;
        }
        return result;
    }
};

int main(){
	Solution s;
	cout<<s.bulbSwitch(999999)<<endl;
	return 0;
}