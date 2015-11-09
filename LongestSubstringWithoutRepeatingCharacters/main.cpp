#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxLength = 1;
       	vector<int> dict(256,-1);
       	if(s.size() == 0){
       		return 0;
       	}
        for(int i = 0; i < s.size(); i++){
        	if(dict[s[i]] >= start){
        		maxLength = max(maxLength, i - start);
        		start = dict[s[i]] + 1;
        	}
        	dict[s[i]] = i;
        }
        maxLength = max(maxLength, (int)s.size() - start);
        return maxLength;
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLongestSubstring("a")<<endl;
	return 0;
}