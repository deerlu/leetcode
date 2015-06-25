#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, tag = 0;
        if(s.size() == 0){
            return 0;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' '){
                count++;
                tag = 1;
            }
            if(s[i] == ' ' && tag == 1){
                break;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLastWord("world      ")<<endl;
    return 0;
}
