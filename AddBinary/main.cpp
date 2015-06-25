#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int result = 0,i,j;
        int tag = 0;
        if( a.size() < b.size()){
            swap(a,b);
        }
        for(i = b.size() - 1, j = a.size() - 1; i >= 0; i--, j--){
            int sum = b[i] - '0' + a[j] - '0' + tag;
            a[j] = sum % 2 + '0';
            if(sum >= 2){
                tag = 1;
            }else{
                tag = 0;
            }
        }
        for(; j >= 0; j--){
            int sum = a[j] - '0' + tag;
            a[j] = sum % 2 + '0';
            if(sum >= 2){
                tag = 1;
            }else{
                tag = 0;
            }
        }
        if(tag == 1){
            return "1" + a;
        }else{
            return a;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.addBinary("1010","1011")<<endl;
    return 0;
}
