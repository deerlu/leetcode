#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> result;
	string letters;
	int length;
	string myDigits;
public:
    vector<string> letterCombinations(string digits) {
        length = digits.size();
        if(length == 0){
        	return result;
        }
        letters.clear();
        myDigits = digits;
        mapToLetters(0);
        return result;
    }

    void mapToLetters(int handleLength){
    	if(handleLength == length){
    		result.push_back(letters);
    	}else{
    		if(myDigits[handleLength] != '1'){
    			int number = myDigits[handleLength] - '2';
    			if(number <= 4){
    				for(int i = 0; i < 3; i++){
    					letters.append(1,'a' + i + number * 3);
    					mapToLetters(handleLength + 1);
    					letters.erase(letters.end() - 1);
    				}
    			}else if(number == 5){
    				for(int i = 0; i < 4; i++){
    					letters.append(1,'a' + i + number * 3);
    					mapToLetters(handleLength + 1);
    					letters.erase(letters.end() - 1);
    				}

    			}else if(number == 6){
    				for(int i = 0; i < 3; i++){
    					letters.append(1,'a' + i + number * 3 + 1);
    					mapToLetters(handleLength + 1);
    					letters.erase(letters.end() - 1);
    				}

    			}else{
    				for(int i = 0; i < 4; i++){
    					letters.append(1,'a' + i + number * 3 + 1);
    					mapToLetters(handleLength + 1);
    					letters.erase(letters.end() - 1);
    				}
    			}
    		}else{
    			mapToLetters(handleLength + 1);
    		}
    	}
    }
};

int main(){
	Solution s;
	vector<string> result = s.letterCombinations("");
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}