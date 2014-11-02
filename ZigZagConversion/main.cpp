#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	int length = s.size();
    	if(nRows == 1){
    		return s;
    	}
        vector<string> out(nRows, "");
        string result = "";
        for(int j = 0; j < length; j++){
        	int a = j / (nRows - 1);
        	int b = j % (nRows - 1);
        	if(a % 2 == 0){
        		out[b].push_back(s[j]);
        	}else if(b == 0){
        		out[nRows - 1].push_back(s[j]);
        	}else{
        		out[nRows - 1 - b].push_back(s[j]);
        	}
        }
        for(int i = 0; i < nRows; i++){
        	result += out[i]; 
        }
        return result;
    }
};

int main(int argc, char** argv){
	string input;
	Solution s;
	cin>>input;
	cout<<s.convert(input,3)<<endl;
	return 0;
}