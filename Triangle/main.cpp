#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int minPath;
	int size;
public:
    int minimumTotal(vector< vector<int> >& triangle) {
    	if(triangle.size() == 0 || triangle[0].size() == 0){
    		return 0;
    	}
        size = triangle.size();
        int minVal;
        vector< vector<int> > dp(size);
        dp[0].push_back(triangle[0][0]);
        for(int i = 1; i < size; i++){
        	for(int j = 0; j < triangle[i].size(); j++){
        		minVal = 0;
        		if(i == j){
        			minVal = dp[i-1][j-1];
        		}else if(j >= 1){
        			minVal = dp[i-1][j-1] > dp[i-1][j] ? dp[i-1][j] : dp[i-1][j-1];
        		}else{
        			minVal = dp[i-1][j];
        		}
        		dp[i].push_back(minVal + triangle[i][j]);
        	}
        }
        minVal = dp[size - 1][0];
        for(int j = 1; j < dp[size -1 ].size(); j++){
        	if(dp[size - 1][j] < minVal){
        		minVal = dp[size - 1][j];
        	}
        }
        return minVal;
    }
};

int main(){
	Solution s;
	vector< vector<int> > v;
	vector<int> row;
	row.push_back(2);
	v.push_back(row);
	row.clear();

	row.push_back(3);
	row.push_back(4);
	v.push_back(row);
	row.clear();

	row.push_back(6);
	row.push_back(5);
	row.push_back(7);
	v.push_back(row);
	row.clear();

	row.push_back(4);
	row.push_back(1);
	row.push_back(8);
	row.push_back(3);
	v.push_back(row);
	row.clear();

	cout<<s.minimumTotal(v)<<endl;
	return 0;
}