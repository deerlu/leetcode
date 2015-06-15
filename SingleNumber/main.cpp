#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	vector<int>::iterator i;
    	for(i = nums.begin(); i != (nums.end() - 1); i++){
    		*(i+1) = *i ^ *(i+1);
    	}
    	return *i;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(4);
	cout<<s.singleNumber(nums)<<endl;
	return 0;
}