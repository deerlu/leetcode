//
//  main.cpp
//  Maximum Subarray
//
//  Created by Ludi on 16/4/21.
//  Copyright © 2016年 Ludi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int maximum = nums[0];
        int accu = nums[0];
        for(int i = 1; i < n; i++){
            if(accu > 0){
                accu += nums[i];
            }else{
                accu = nums[i];
            }
            
            if(accu > maximum){
                maximum = accu;
            }
        }
        return maximum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}
