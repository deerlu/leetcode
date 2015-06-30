#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1,mid;
        if(nums.size() == 0){
            return 0;
        }
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < target){
                if(mid + 1 == nums.size() || nums[mid + 1] > target){
                    return mid + 1;
                }
                left = mid + 1;
            }else if(nums[mid] > target){
                if(mid - 1 < 0 || nums[mid - 1] < target){
                    return mid;
                }
                right = mid - 1;
            }else{
                break;
            }
        }
        if(left <= right){
            return mid;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);

    cout<<s.searchInsert(nums,0)<<endl;
    return 0;
}
