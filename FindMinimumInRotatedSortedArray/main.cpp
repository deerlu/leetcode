#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int length = num.size();
        int left = 0;
    	int right = length - 1;
        for(; left < right; ){
        	int mid = (left + right) / 2;
        	if(num[left] < num[mid] && num[mid] < num[right])
        	{
        		right = mid;
        	}else if(num[left] < num[mid] && num[mid] > num[right]){
        		left = mid;
        	}else if(num[left] > num[mid] && num[mid] < num[right]){
                right = mid;
            }
            if(left >= right || right - left == 1){
                break;
            }
        }
        return num[left] < num[right] ? num[left] : num[right];
    }
};

int main(int argc, char ** argv){
	Solution s;
	std::vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	cout<<s.findMin(v)<<endl;
	return 0;
}