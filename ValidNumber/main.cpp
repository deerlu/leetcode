#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	bool isInteger(string s){
		if(s.size() > 0 && (s[0] == '+' || s[0] == '-')){
			s.erase(0,1);
		}

		if(s.size() == 0){
			return false;
		}else{
			for(int i = 0; i < s.size(); i++){
				if(!(s[i] >= '0' && s[i] <= '9')){
					return false;
				}
			}
		}
		return true;
	}

	bool isDecimal(string s){
		string::size_type i = s.find('.');
		if(i != string::npos){
			string first = s.substr(0,i);
        	string second = s.substr(i+1);
        	if(first.size() == 0 || isInteger(first)){
        		if(first.size() == 0 && second.size() == 0){
        			return false;
        		}
        		for(int i = 0; i < second.size(); i++){
					if(!(second[i] >= '0' && second[i] <= '9')){
						return false;
					}
				}
				return true;
        	}else{
        		return false;
        	}
		}else{
			return false;
		}
	}

public:
    bool isNumber(string s) {
    	
    	int pos = 0;
    	while(pos < s.size() && s[pos] == ' '){
    		s.erase(pos,1);
    	}
    	pos = s.size() - 1;
    	while(pos >= 0 && s[pos] == ' '){
    		s.erase(pos);
    		pos--;
    	}

    	if(s.size() > 0 && (s[0] == '+' || s[0] == '-')){
			s.erase(0,1);
		}

        string::size_type i = s.find('e');
        if(i != string::npos){
        	string first = s.substr(0,i);
        	string second = s.substr(i+1);
        	/*if(second.size() == 1 && (second[0] == '+' || second[0] == '-')){
        		return false;
        	}*/
        	if(isInteger(second)){
        		if(isDecimal(first) || isInteger(first)){
        			return true;
        		}
        		return false;
        	}else{
        		return false;
        	}
        }else{
        	return isInteger(s) || isDecimal(s);
        }
    }
};

int main(){
	Solution s;
	cout<<s.isNumber("4e+")<<endl;
	return 0;
}