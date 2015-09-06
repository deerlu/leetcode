#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	set<int> s;
    	for(int i = 0; i < nums.size(); i++){
    		auto iter = s.find(nums[i]);
    		if(iter == s.end()){
    			s.insert(nums[i]);
    		}else{
    			s.erase(iter);
    		}
    	}
        vector<int> result;
        for(auto i = s.begin(); i != s.end(); i++){
        	result.push_back(*i);
        }
        return result;
    }
};

int main(){
	std::vector<int> v;
	Solution s;
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(5);
	v = s.singleNumber(nums);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<endl;
	}
	return 0;
}