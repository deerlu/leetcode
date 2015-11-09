#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> ChangeToPostfix(string s){
        vector<string> result;
        stack<char> operators;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                while(!operators.empty()){
                    char top = operators.top();
                    if(top == '+' || top == '-'){
                        operators.pop();
                        string tmp = "";
                        tmp += top;
                        result.push_back(tmp);
                    }else{
                        break;
                    }
                }
                operators.push('+');
            }else if(s[i] == '-'){
                while(!operators.empty()){
                    char top = operators.top();
                    if(top == '+' || top == '-'){
                        operators.pop();
                        string tmp = "";
                        tmp += top;
                        result.push_back(tmp);
                    }else{
                        break;
                    }
                }
                operators.push('-');
            }else if(s[i] == '('){
                operators.push('(');
            }else if(s[i] == ')'){
                char top = ' ';
                while(top != '('){
                    top = operators.top();
                    operators.pop();
                    if(top != '('){
                        string tmp = "";
                        tmp += top;
                        result.push_back(tmp);
                    }
                }
            }else if(s[i] >= '0' && s[i] <= '9'){
                string tmp = "";
                while(s[i] >= '0' && s[i] <= '9'){
                    tmp += s[i];
                    i++;
                }
                i--;
                result.push_back(tmp);
            }
        }
        while(!operators.empty()){
            string tmp = "";
            char top = operators.top();
            operators.pop();
            tmp += top;
            result.push_back(tmp);
        }
        return result;
    }

    int CalPostfix(vector<string>& postfix){
        stack<int> operands;
        int left;
        int right;
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
            }else{
                stringstream ss;
                ss<<postfix[i];
                int tmp;
                ss>>tmp;
                operands.push(tmp);
            }
        }
        return operands.top();
    }

    int calculate(string s) {
        vector<string> postfix = ChangeToPostfix(s);
        return CalPostfix(postfix);
    }
};

int main(){
	Solution s;
	cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
	return 0;
}