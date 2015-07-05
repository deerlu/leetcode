#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int length = nums.size();
    	if(length == 0){
    		return 0;
    	}
    	int tmp = nums[0],count = 1;
    	for(vector<int>::iterator i = nums.begin() + 1; i != nums.end(); ){
    		if(tmp == *i){
                if(count < 2){
                    count++;
                    i++;
                }else{
                    while(i != nums.end() && tmp == *i){
                        i = nums.erase(i);
                    }
                }
    		}else{
    			tmp = *i;
    			i++;
                count = 1;
    		}
    	}
        return nums.size();
    }
};

int main(){
	Solution s;
	vector<int> number;
	number.push_back(1);
	number.push_back(1);
	number.push_back(1);
	/*number.push_back(2);
	number.push_back(2);
	number.push_back(3);*/
	cout<<s.removeDuplicates(number)<<endl;
	return 0;
}