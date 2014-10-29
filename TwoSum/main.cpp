#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        tr1::unordered_map<int,int> hash;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            int tmp = target - numbers[i];
            if(hash.find(tmp) != hash.end()){
                result.push_back(hash[tmp] + 1);
                result.push_back(i+1);
                return result;
            }
            hash[numbers[i]] = i;
        }
    }
};

int main()
{
    Solution s;
    vector<int> v;
    vector<int> solution;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    solution = s.twoSum(v,26);
    cout<<solution[0]<<" "<<solution[1]<<endl;
    return 0;
}
