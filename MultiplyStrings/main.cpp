#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0){
            return "";
        }
        string result(num1.size() + num2.size(), '0');
        
        for(int i = num1.size() - 1; i >= 0; i--){
            for(int j = num2.size() - 1; j >= 0; j--){
                int bit1 = num1.size() - i - 1;
                int bit2 = num2.size() - j - 1;
                int product = (num1[i] - '0') * (num2[j] - '0') + result[bit1 + bit2] - '0';
                if(product >= 10){
                    int k = 0;
                    while(product >= 10){
                        result[bit1 + bit2 + k] = product % 10 + '0';
                        product = product / 10 + result[bit1 + bit2 + k + 1] - '0';
                        if(product < 10){
                            result[bit1 + bit2 + k + 1] = product + '0';
                        }
                        k++;
                    }
                }else{
                    result[bit1 + bit2] = product + '0';
                }
                
            }
        }
        int i;
        for(i = result.size() - 1; i >= 0; i--){
            if(result[i] != '0'){
                break;
            }
        }
        if(i < 0){
            return "0";
        }
        string tmp;
        for(int j = i; j >= 0; j--){
            tmp.push_back(result[j]);
        }
        return tmp;
    }
};

int main(){
    Solution s;
    cout<<s.multiply("123","456")<<endl;
    return 0;
}