#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int tail0,head2,cur = 0;
        tail0 = 0;
        head2 = nums.size() - 1;
        while(cur <= head2){
            if(nums[cur] == 0){
                swap(nums[cur],nums[tail0]);
                tail0++;
                cur++;
            }else if(nums[cur] == 2){
                swap(nums[cur],nums[head2]);
                head2--;
            }else{
                cur++;
            }
        }
        
    }
};

int main(){
	vector<int> nums;
	Solution s;
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	
	s.sortColors(nums);
	for(int i = 0; i < nums.size(); i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}