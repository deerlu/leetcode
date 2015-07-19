#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        int left,right;
        for(vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++){
        	if(i->compare("+") == 0){
        		right = operands.top();
        		operands.pop();
        		left = operands.top();
        		operands.pop();
        		operands.push(left + right);
        	}else if(i->compare("-") == 0){
        		right = operands.top();
        		operands.pop();
        		left = operands.top();
        		operands.pop();
        		operands.push(left - right);
        	}else if(i->compare("*") == 0){
        		right = operands.top();
        		operands.pop();
        		left = operands.top();
        		operands.pop();
        		operands.push(left * right);
        	}else if(i->compare("/") == 0){
        		right = operands.top();
        		operands.pop();
        		left = operands.top();
        		operands.pop();
        		operands.push(left / right);
        	}else{
        		stringstream ss;
        		ss<<(*i);
        		int tmp;
        		ss>>tmp;
        		operands.push(tmp);
        	}
        }
        return operands.top();
    }
};

int main(){
	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("-");
	v.push_back("3");
	v.push_back("*");
	Solution s;
	cout<<s.evalRPN(v)<<endl;
	return 0;
}