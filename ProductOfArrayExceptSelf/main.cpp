#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> result(size);
    	if(!size){
    		return result;
    	}
    	int count = 1;
        for(int i = 0; i < size; i++){
        	result[i] = count;
        	count *= nums[i];
        }

        count = 1;
        for(int i = size - 1; i >= 0; i--){
        	result[i] *= count;
        	count *= nums[i];
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<int> v;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	v = s.productExceptSelf(nums);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}