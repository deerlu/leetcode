#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator viStart = find(nums.begin(), nums.end(), val), viEnd;
        viEnd = viStart;
        while(viEnd != nums.end() && *viEnd == val) viEnd++;
        nums.erase(viStart,viEnd);
        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);
    cout<<s.removeElement(nums, 2)<<endl;
    return 0;
}
