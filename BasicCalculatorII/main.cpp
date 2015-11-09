#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int string2int(string tmp){
        stringstream ss;
        ss<<tmp;
        int result;
        ss>>result;
        return result;
    }
    int calculatePostfix(vector<string>& postfix){
        stack<int> operands;
        int result = 0;
        int left,right;
        for(int i = 0; i < postfix.size(); i++){
            if(postfix[i] == "+"){
                right = operands.top();
                operands.pop();
                left = operands.top();
                operands.pop();
                operands.push(left + right);
            }else if(postfix[i] == "-"){
                right = operands.top();
                operands.pop();
                left = operands.top();
                operands.pop();
                operands.push(left - right);
            }else if(postfix[i] == "*"){
                right = operands.top();
                operands.pop();
                left = operands.top();
                operands.pop();
                operands.push(left * right);
            }else if(postfix[i] == "/"){
                right = operands.top();
                operands.pop();
                left = operands.top();
                operands.pop();
                operands.push(left / right);
            }else{
                int tmp = string2int(postfix[i]);
                operands.push(tmp);
            }
        }
        return operands.top();
    }

    int calculate(string s) {
    	stack<char> operators;
    	vector<string> postfix;
    	
    	for(int i = 0; i < s.size(); ){
    		if(s[i] == '+' || s[i] == '-'){
    			while(!operators.empty()){
    				char top = operators.top();
    				operators.pop();
                    string tmp = "";
                    tmp += top;
    				postfix.push_back(tmp);
    			}
    			operators.push(s[i]);
                i++;
    		}else if(s[i] == '*' || s[i] == '/'){
    			while(!operators.empty()){
    				char top = operators.top();
    				if(top == '*' || top == '/'){
    					operators.pop();
    					string tmp = "";
                        tmp += top;
                        postfix.push_back(tmp);
    				}else{
                        break;
                    }
    			}
    			operators.push(s[i]);
                i++;
    		}else if (s[i] != ' '){
                string tmp = "";
    			while(s[i] >= '0' && s[i] <= '9'){
                    tmp += s[i];
                    i++;
                }
                postfix.push_back(tmp);
    		}else{
                i++;
            }
    	}
    	while(!operators.empty()){
    		char top = operators.top();
    		operators.pop();
    		string tmp = "";
            tmp += top;
            postfix.push_back(tmp);
    	}
        
        return calculatePostfix(postfix);
    }
};

int main(){
	Solution s;
	cout<<s.calculate(" 3+5 / 2 ")<<endl;
	return 0;
}