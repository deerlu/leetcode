#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int maxLength = 1;
    	if(nums.size() == 0){
    		return 0;
    	}
    	sort(nums.begin(),nums.end());
    	int tmp = nums[0] + 1;
    	int length = 1;
    	for(int i = 1; i != nums.size(); i++){
    		if(tmp == nums[i]){
    			tmp++;
    			length++;
    		}else if(tmp - 1 != nums[i]){
    			tmp = nums[i] + 1;
    			if(length > maxLength){
    				maxLength = length;
    			}
    			length = 1;
    		}
    	}
    	if(length > maxLength){
    		maxLength = length;
    	}
    	return maxLength;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	
	cout<<s.longestConsecutive(nums)<<endl;
	return 0;
}