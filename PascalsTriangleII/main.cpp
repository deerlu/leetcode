#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> result;
    	rowIndex++;
    	result.push_back(1);
    	if(rowIndex == 1){
    		return result;
    	}
    	int tmp = 1;
    	for(int i = 1; i < rowIndex - 1; i++){
            int consult = tmp / i;
            int remain = tmp % i;
    		tmp = (rowIndex - i) * consult + (rowIndex - i) * remain / i;
    		result.push_back(tmp);
    	}
    	result.push_back(1);
    	return result;
    }
};

int main(){
	Solution s;
	vector<int> v = s.getRow(30);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<endl;
	}
	return 0;
}