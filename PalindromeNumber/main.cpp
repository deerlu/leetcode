#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x,result = 0,y;
        if(x < 0){
            return false;
        }
        while(tmp != 0){
            y = tmp % 10;
            tmp = tmp /  10;
            result = result * 10 + y;
        }
        if(result == x){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int x = 123321;
    cout<<s.isPalindrome(x)<<endl;
    return 0;
}
