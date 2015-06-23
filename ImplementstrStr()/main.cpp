#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if(pos != string::npos){
            return pos;
        }else{
            return -1;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("123","4")<<endl;
    return 0;
}
