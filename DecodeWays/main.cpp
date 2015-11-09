#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    	int result = 0;
    	if(s.size() == 0){
    		return 0;
    	}else if(s.size() == 1){
    		if(s[0] == '0')
    			return 0;
    		return 1;
    	}

    	int dp[s.size()];
    	if(s[0] == '0'){
    		dp[0] = 0;
    	}else{
    		dp[0] = 1;
    	}

    	int tmp = s[0] - '0';
    	tmp = tmp * 10 + s[1] - '0';
    	if(tmp >= 10 && tmp <= 26){
    		if(s[1] == '0'){
    			dp[1] = 1;
    		}else{
    			dp[1] = dp[0] + 1;
    		}
    	}else{
    		if(s[1] == '0'){
    			dp[1] = 0;
    		}else{
    			dp[1] = dp[0];
    		}
    	}
    	for(int i = 2; i < s.size(); i++){
    		int tmp = s[i - 1] - '0';
    		tmp = tmp * 10 + s[i] - '0';
    		if(tmp >= 10 && tmp <= 26){
    			if(s[i] == '0'){
    				dp[i] = dp[i - 2];
    			}else{
    				dp[i] = dp[i - 1] + dp[i - 2];
    			}
    		}else{
    			if(s[i] == '0'){
    				dp[i] = 0;
    			}else{
    				dp[i] = dp[i - 1];
    			}
    		}
    	}
        return dp[s.size() - 1];
    }
};

int main(){
	Solution s;
	cout<<s.numDecodings("301")<<endl;
	return 0;
}