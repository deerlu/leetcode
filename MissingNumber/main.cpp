#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsSum = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++){
        	numsSum += nums[i];
        }
        int sum = (length + 1) * length / 2;
        return sum - numsSum;
    }
};

int main(){
	Solution s;
	std::vector<int> v;
	v.push_back(0);
    v.push_back(2);
    v.push_back(1);
	cout<<s.missingNumber(v)<<endl;
	return 0;
}