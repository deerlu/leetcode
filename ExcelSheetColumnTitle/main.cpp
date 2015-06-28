#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	vector<int> vi;
    	string result;
        while(n != 0){
        	vi.push_back((n-1) % 26);
        	n = (n-1) / 26;
        }
        for(vector<int>::iterator vii = vi.end()-1; vii >= vi.begin();vii--){
        	result.push_back(*vii + 'A');
        }
        return result;
    }
};

int main(){
	Solution s;
	cout<<s.convertToTitle(53)<<endl;
	return 0;
}