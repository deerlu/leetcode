#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator iter1,iter2;
        int i = 0;
        nums1.erase(nums1.begin() + m,nums1.end());
        iter1 = nums1.begin();
        iter2 = nums2.begin();
        while(i != n){
        	while(iter1 < nums1.end() && *iter1 <= *iter2) iter1++;
        	iter1 = nums1.insert(iter1,*iter2);
        	iter1++;
        	iter2++;
        	i++;
        }

    }
};

int main(){
	vector<int> nums1,nums2;
	nums1.push_back(4);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(5);
	nums2.push_back(6);
	Solution s;
	s.merge(nums1,1,nums2,5);
	for(int i = 0; i < nums1.size(); i++){
		cout<<nums1[i]<<endl;
	}
	return 0;
}