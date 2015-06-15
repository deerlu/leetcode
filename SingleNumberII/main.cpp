#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mii;
        vector<int>::iterator vii;
        for(vii = nums.begin(); vii != nums.end(); vii++){
        	mii[*vii] += 1;
        }
        map<int,int>::iterator miii;
        for(miii = mii.begin(); miii != mii.end(); miii++){
        	if(miii->second != 3){
        		return miii->first;
        	}
        }
    }
};

int main(){
	Solution s;
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(1);
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(2);
	vi.push_back(2);
	vi.push_back(4);
	vi.push_back(4);
	cout<<s.singleNumber(vi)<<endl;
	return 0;
}