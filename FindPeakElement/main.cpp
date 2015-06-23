#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[nums.size()-1] > nums[nums.size()-2]){
            return nums.size()-1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    cout<<s.findPeakElement(numbers)<<endl;
    return 0;
}
