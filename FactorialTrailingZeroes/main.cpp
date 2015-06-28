#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count5 = 0;
 
        for(long i = 5; i > 0 && i <= n; ){
        	count5 += (n / i);
        	i = i * 5;
        }

        return count5;
    }
};

int main(){
	Solution s;
	cout<<s.trailingZeroes(1808548329)<<endl;
	return 0;
}