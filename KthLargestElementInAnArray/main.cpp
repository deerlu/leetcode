#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return *(nums.end() - k);
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	cout<<s.findKthLargest(nums,2)<<endl;
	return 0;
}