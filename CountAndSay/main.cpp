#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	if(n == 0){
    		return "";
    	}
    	string now = "1";
    	string tmpString = "";
    	int count;
        for(int i = 1; i < n; i++){
        	char tmpChar = now[0];
        	count = 1;
        	tmpString = "";
        	for(int j = 1; j < now.size(); j++){
        		if(now[j] == tmpChar){
        			count++;
        		}else{
        			char tmp = count + '0';
        			tmpString += tmp;
        			tmpString += tmpChar;
        			tmpChar = now[j];
        			count = 1;
        		}
        	}
        	char tmp = count + '0';
        	tmpString += tmp;
        	tmpString += tmpChar;
        	now = tmpString;
        }
        return now;
    }
};

int main(){
	Solution s;
	cout<<s.countAndSay(5)<<endl;
	return 0;
}