#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vs(128);
        vector<int> vt(128);
        for(int i = 0; i < s.size(); i++){
            if(vs[s[i]] != vt[t[i]]){
                return false;
            }
            vs[s[i]] = i + 1;
            vt[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isIsomorphic("egg","add")<<endl;
    return 0;
}
