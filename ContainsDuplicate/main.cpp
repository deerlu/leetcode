#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> si;
        vector<int>::iterator vii;
        for(vii = nums.begin(); vii != nums.end(); vii++){
        	if(si.find(*vii) != si.end()){
        		return true;
        	}
        	si.insert(*vii);
        }
        return false;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	
	cout<<s.containsDuplicate(nums)<<endl;
	return 0;
}