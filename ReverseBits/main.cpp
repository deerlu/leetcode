#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseNum = 0;
        int bitCount = 0;
        while(n != 0){
            reverseNum = reverseNum * 2 + n % 2;
            n = n / 2;
            bitCount++;
        }
        while(bitCount < 32){
            reverseNum *= 2;
            bitCount++;
        }
        return reverseNum;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(43261596)<<endl;
    return 0;
}
