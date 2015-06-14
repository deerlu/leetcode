#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
	int majorityElement(vector<int>& nums){
        multiset<int> mi;
        vector<int>::iterator vii = nums.begin();
        int times = nums.size() / 2.0;
        while(vii != nums.end()){
            mi.insert(*vii);
            vii++;
        }
        
        for(multiset<int>::iterator mii = mi.begin(); mii != mi.end(); ){
            size_t miiTimes = mi.count(*mii);
            if(miiTimes > times){
                return *mii;
            }
            mii = mi.upper_bound(*mii);
        }
		
	}
};

int main()
{
	Solution s;
	vector<int> vi;
	vi.push_back(1);
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(2);

	cout<<"123 "<<s.majorityElement(vi);
	return 0;
}