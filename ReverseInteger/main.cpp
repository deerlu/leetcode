#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int factor = 1,tmp;
        long result = 0;
        if(x < 0){
        	factor = -1;
        	x = -x;
        }
        while(x != 0){
        	tmp = x % 10;
        	result = result * 10 + tmp;
        	x = x / 10;
        }
        if(result * factor >= INT_MAX || result * factor <= INT_MIN) return 0;
        return result * factor;
    }
};

int main(){
	Solution s;
	cout<<s.reverse(1534236469)<<endl;
	return 0;
}