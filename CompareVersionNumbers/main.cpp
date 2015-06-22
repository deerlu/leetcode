#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int a,b,i,j;
    	for(i = 0,j = 0; i < version1.size() || j < version2.size(); ){
            a = 0;
            b = 0;
    		while(i < version1.size() && version1[i] != '.'){
                a = 10 * a + version1[i] - '0';
                i++;
            }

            while(j < version2.size() && version2[j] != '.'){
                b = 10 * b + version2[j] - '0';
                j++;
            }
            
    		if(a > b){
    			return 1;
    		}
    		if(a < b){
    			return -1;
    		}

            if(version1[i] == '.'){
                i++;
            }

            if(version2[j] == '.'){
                j++;
            }
    	}
    	return 0;
        	
    }
};

int main(){
	Solution s;
	string s1 = "13.37.6";
	string s2 = "13.37.5";
	cout<<s.compareVersion(s1,s2)<<endl;
	return 0;
}