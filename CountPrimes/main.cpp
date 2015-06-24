#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> v(n);
        for(int i = 0; i < v.size(); i++){
            v[i] = true;
        }
        for(int i = 2; i * i < n; i++){
            if(v[i]){
                for(int j = i; i * j < n; j++){
                    v[i*j] = false;
                }
            }
        }
        for(int i = 2; i < n; i++){
            if(v[i]){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.countPrimes(1500000)<<endl;
    return 0;
}
