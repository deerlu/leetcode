#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	int factor[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    	string str(n,' ');
    	string result(n,' ');
    	for(int i = 0; i < n; i++){
    		str[i] = '0' + i + 1;
    	}
    	int remain = k - 1;
    	for(int i = n - 1; i >= 0; i--){
    		int consult = remain / factor[i];
    		result[n - 1 - i] = str[consult];
    		str.erase(consult,1);
    		remain = remain % factor[i];
    	}
        return result;
    }
};

int main(){
	Solution s;
	cout<<s.getPermutation(3,3)<<endl;
	return 0;
}