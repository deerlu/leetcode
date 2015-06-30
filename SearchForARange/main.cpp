#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int left = 0, right = nums.size() - 1,mid;
        if(nums.size() == 0){
            return result;
        }
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                break;
            }
        }
        if(left <= right){
            int tmp = mid;
            while(mid--){
                if(nums[mid] != target){
                    break;
                }
            }
            result[0] = mid + 1;
            while(tmp != nums.size()){
                if(nums[tmp] != target){
                    break;
                }
                tmp++;
            }
            result[1] = tmp - 1;
            return result;
        }else{
            return result;
        }

    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(7);
    nums = s.searchRange(nums,7);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
