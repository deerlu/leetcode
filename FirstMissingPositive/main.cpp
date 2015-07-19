#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int count = 1;
        sort(nums.begin(),nums.end());
        vector<int>::iterator i;
        for(i = nums.begin(); i != nums.end() && *i <= 0; i++){
        }

        while(i != nums.end()){
        	if(*i == count){
        		count++;
        		i++;
        	}else if((*i + 1) == count){
        		i++;
        	}else{
        		return count;
        	}
        }
        return count;
    }
};

int main(){
	vector<int> v;
	Solution s;
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	cout<<s.firstMissingPositive(v)<<endl;
	return 0;
}