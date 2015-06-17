#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0,repre;
        for(int i = s.size() - 1; i >= 0; i--){
        	switch (s[i]){
        		case 'I': repre = 1;break;
        		case 'V': repre = 5;break;
        		case 'X': repre = 10;break;
        		case 'L': repre = 50;break;
        		case 'C': repre = 100;break;
        		case 'D': repre = 500;break;
        		case 'M': repre = 1000;break;
        	}
        	if((i + 1) < s.size()){
        		if((repre == 1 && (s[i+1] == 'V' || s[i+1] == 'X'))
        		|| (repre == 10 && (s[i+1] == 'L' || s[i+1] == 'C'))
        		|| (repre == 100 && (s[i+1] == 'D' || s[i+1] == 'M'))){
        			repre = -repre;
        		}
        	}
        	result += repre;
        }
        return result;
    }
};

int main(){
	Solution s;
	cout<<s.romanToInt("MCMXCVIII")<<endl;
	return 0;
}