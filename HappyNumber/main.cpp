#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	int sum = 0;
    	int tmp = n;
    	set<int> history;
		for(;;)
		{

			while(tmp != 0)
			{
				int x = tmp % 10;
				sum += x * x;
				tmp /= 10;
			}
			if(sum == 1)
			{
				return true;
			}
			else
			{
				if(history.find(sum) != history.end())
				{
					return false;
				}
				else
				{
					history.insert(sum);
				}
				tmp = sum;
				sum = 0;
			}
		}
    }
};

int main(){
	Solution s;
	cout<<s.isHappy(19)<<endl;
	return 0;
}