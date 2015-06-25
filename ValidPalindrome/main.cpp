#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int valA = -1,valB = -1;
        if(s.size() == 0){
            return true;
        }
        for(int i = 0,j = s.size() - 1; i < j; i++,j--){
            while(i < s.size() && !isalnum(s[i])) i++;
            if(s[i] >= 'A' && s[i] <= 'Z'){
                valA = s[i] - 'A';
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                valA = s[i] - 'a';
            }else if(s[i] >= '0' && s[i] <= '9'){
                valA = s[i];
            }
            while(j >= 0 && !isalnum(s[j])) j--;
            if(i > j && valA == valB && valA == -1) return true;
            if(s[j] >= 'A' && s[j] <= 'Z'){
                valB = s[j] - 'A';
            }else if(s[j] >= 'a' && s[j] <= 'z'){
                valB = s[j] - 'a';
            }else if(s[j] >= '0' && s[j] <= '9'){
                valB = s[j];
            }

            if(valA != -1 && valB != -1 && valA != valB){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(" apG0i4maAs::sA0m4i0Gp0")<<endl;
    return 0;
}
