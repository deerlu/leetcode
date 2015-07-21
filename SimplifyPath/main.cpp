#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string::size_type i,j = 0;
        vector<string> pathVec;
        string result,tmp;
        while(true){
            i = j;
            j = path.find('/',i+1);
            if(i == string::npos){
                break;
            }else if (j == string::npos){
                if(i + 1 != path.size()){
                    tmp = path.substr(i+1);
                    if(tmp.compare("..") == 0){
                        if(pathVec.size() != 0){
                    		pathVec.erase(pathVec.end()-1);
                		}
                    }else if(tmp.compare(".") != 0){
                        pathVec.push_back(tmp);
                    }
                }
                break;
            }else{
            	if(j-i-1 > 0){
               		tmp = path.substr(i+1,j-i-1);
                	if(tmp.compare("..") == 0){
                		if(pathVec.size() != 0){
                    		pathVec.erase(pathVec.end()-1);
                		}
                	}else if(tmp.compare(".") != 0){
                    	pathVec.push_back(tmp);
                	}
            	}
            }
        }
        if(pathVec.size() == 0){
        	result += "/";
        }else{
        	for(int i = 0; i < pathVec.size(); i++){
            	result += "/" + pathVec[i];
        	}
    	}
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.simplifyPath("////")<<endl;
    return 0;
}