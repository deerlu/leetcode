#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void changeOrder(std::vector<int> &nums, int start){
		int end = nums.size() - 1;
		while(start < end){
			int tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;
			start++;
			end--;
		}
	}

    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector< int> > result;
        sort(nums.begin(), nums.end());//sort the array first!
        vector<int> r = nums;
        while(true){
        	int min = 0,i;
        	result.push_back(r);
        	for(i = r.size() - 1; i > 0; i--){
        		if(r[i - 1] < r[i]){
        			for(int j = i; j < r.size(); j++){
        				if(r[i - 1] < r[j]){
        					min = j;
        				}
        			}
        			break;
        		}
        	}
        	if(i == 0){
        		return result;
        	}
        	int tmp = r[i - 1];
        	r[i - 1] = r[min];
        	r[min] = tmp;
        	changeOrder(r, i);
        }
    }
};

int main(){
	Solution s;
	vector<int> test;
	test.push_back(1);
	test.push_back(1);
	test.push_back(2);
	vector< vector <int> > result = s.permuteUnique(test);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}