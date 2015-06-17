#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int tmp,tag = 0;
       	int factor = 1,i;
       	for(i = 0; i < str.size(); i++){
       		if(str[i] != ' '){
       			break;
       		}
       	}
       	if(str[i] == '-' || str[i] == '+'){
       		if(str[i] == '-'){
       			factor = -1;
       		}
       		i++;
       	}
       	while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
       		result = result * 10 + str[i] - '0';
       		if(result * factor >= INT_MAX) return INT_MAX;
       		if(result * factor <= INT_MIN) return INT_MIN;
       		i++;
       	}
        return result * factor;
    }
};

int main(){
	Solution s;
	cout<<s.myAtoi("   -0012a   ");
	return 0;
}