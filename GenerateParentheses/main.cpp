#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void generateParenthesis(vector<string>& result, string s, int leftRemained, int rightToBeAdded){
        if(leftRemained == 0 && rightToBeAdded == 0){
            result.push_back(s);
        }
        if(leftRemained > 0){
            generateParenthesis(result, s + "(", leftRemained - 1, rightToBeAdded + 1);
        }
        if(rightToBeAdded > 0){
            generateParenthesis(result, s + ")", leftRemained, rightToBeAdded - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
    	vector<string> result;
        generateParenthesis(result, "", n, 0);
        return result;
    }
};

int main(){
	Solution s;
	vector<string> result = s.generateParenthesis(3);
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}