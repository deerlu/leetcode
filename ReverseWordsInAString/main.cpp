#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string result = "";
        string word = "";
        for(int i = s.size() - 1; i >= 0; ){
        	while(i >= 0 && s[i] == ' ') i--;
        	while(i >= 0 && s[i] != ' ') {
        		word = s[i] + word;
        		i--;
        	}
        	if(word.size() > 0){
        		result = result + word + " ";
        		word = "";
        	}
        }
        if(result.size() > 0){
        	result.erase(result.size() - 1);
    	}
        s = result;
    }
};

int main(){
	Solution s;
	string str = "";
	s.reverseWords(str);
	cout<<str.size()<<endl;
	cout<<str<<endl;
	return 0;
}