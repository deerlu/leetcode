#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        if(length == 0 || k % length == 0 || k == 0){
            return;
        }
        if(length < k){
            k = k % length;
        }
        vector<int> result;
        for(int i = length - k; i < length; i++){
            result.push_back(nums[i]);
        }
        for(int i = 0; i <= length - k - 1; i++){
            result.push_back(nums[i]);
        }
        nums = result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    s.rotate(nums,6);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
