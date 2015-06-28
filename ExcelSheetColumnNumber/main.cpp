#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        int factor = 1;
        for(int i = s.size() - 1; i >= 0; i--){
        	number += (s[i] - 'A' + 1) * factor;
        	factor *= 26;
        }
        return number;
    }
};

int main(){
	Solution s;
	cout<<s.titleToNumber("BA")<<endl;
	return 0;
}