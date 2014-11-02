#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> in;
    	for(int i = 0; i < s.size(); i++){
    		switch(s[i]){
    			case '(':
    			case '[':
    			case '{':
    				in.push(s[i]);
    				break;
    			case ')':
				case ']':
				case '}':
				{
					if(!in.empty()
					&& (in.top() == '(' && s[i] == ')'
					|| in.top() == '[' && s[i] == ']'
					|| in.top() == '{' && s[i] == '}')){
						in.pop();
					}else{
						return false;
					}

					break;
				}
				default:
					return false;
    		}
    	}
    	if(in.empty()){
    		return true;
    	}
    	return false;
    }
};

int main(int argc, char ** argv){
	Solution s;
	string str;
	cin>>str;
	cout<<s.isValid(str)<<endl;
	return 0;
}