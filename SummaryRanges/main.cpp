#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        vector<int>::iterator vii;
        int start,end;
        string range;
        stringstream ss;
        for(vii = nums.begin(); vii != nums.end(); ){
        	ss.clear();
        	ss<<(*vii);
        	start = *vii;
        	end = *vii;
        	while(vii != nums.end() && end == *vii){
        		end++;
        		vii++;
        	}
        	if(start != (end-1)){
        		ss<<"->"<<(end-1);
        	}
 			ss>>range;
        	result.push_back(range);
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	vector<string> vs;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(8);
	vs = s.summaryRanges(nums);
	for(int i = 0; i < vs.size(); i++){
		cout<<vs[i]<<endl;
	}
	return 0;
}