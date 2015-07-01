#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes;
        int factor = 2;        
        codes.push_back(0);
        if(n == 0){
        	return codes;
        }
        codes.push_back(1);
        for(int i = 1; i < n; i++){
        	for(int j = codes.size() - 1; j >= 0; j--){
        		codes.push_back(codes[j] + factor);
        	}
        	factor = factor * 2;
        }
        return codes;
    }
};

int main(){
	Solution s;
	vector<int> codes = s.grayCode(1);
	for(int i = 0; i < codes.size(); i++){
		cout<<codes[i]<<endl;
	}
	return 0;
}