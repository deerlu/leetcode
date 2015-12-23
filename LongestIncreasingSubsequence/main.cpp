#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i,j;
        vector<int> dp(nums.size(),1);
        for(i = 0; i < nums.size(); i++){
            for(j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int maxLength = dp[0];
        for(i = 1; i < dp.size(); i++){
            if(maxLength < dp[i]){
                maxLength = dp[i];
            }
        }
        return maxLength;
    }
    
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(4);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(6);
    cout<<s.lengthOfLIS(nums)<<endl;
    return 0;
}