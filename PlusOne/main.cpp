#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(8);
    digits.push_back(9);
    digits.push_back(9);
    digits = s.plusOne(digits);
    for(int i = 0; i < digits.size(); i++){
        cout<<digits[i];
    }
    cout<<endl;
    return 0;
}
