#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	vector<int> b(n);
    	b[0] = 1;
    	b[1] = 1;
    	int tmp;
    	for(int i = 2; i <= n; i++){
    		tmp = 0;
    		for(int k = 0; k < i; k++){
    			tmp += (b[k] * b[i-1-k]);
    		}
    		b[i] = tmp;
    	}
    	return b[n];
    }
};

int main(){
	Solution s;
	cout<<s.numTrees(9)<<endl;
	return 0;
}