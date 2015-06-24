#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            int tmp = n % 2;
            n = n / 2;
            if(tmp == 1){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.hammingWeight(11)<<endl;
    return 0;
}
