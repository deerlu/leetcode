#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int last = 0,i,min;
    	vector<int>::iterator vii,mini;
        if(nums.size() == 0){
        	return;
        }
        for(i = nums.size() - 1; i > 0; i--){
        	if(nums[i-1] < nums[i]){
        		min = nums[i];
        		mini = nums.begin() + i;
        		for(vii = mini; vii < nums.end(); vii++){
        			if(*vii > nums[i-1] && *vii < min){
        				min = *vii;
        				mini = vii;
        			}
        		}
        		nums.erase(mini);
        		vii = nums.insert(nums.begin() + i - 1,min);
        		sort(vii + 1,nums.end());
        		return;
        	}
	    }
        
        if(i == 0){
        	sort(nums.begin(),nums.end());
        }
    }
};

int main(){
	vector<int> nums;
	Solution s;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(0);

	s.nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}