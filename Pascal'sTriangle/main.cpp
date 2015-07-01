#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        cout<<"123";
    	vector< vector<int> > triangle;
    	vector<int> row;
    	if(numRows < 1){
    		return triangle;
    	}
    	row.push_back(1);
    	triangle.push_back(row);
        for(int i = 1; i < numRows; i++){
        	row.clear();
        	row.push_back(1);
        	for(int j = 0; j < triangle[i-1].size() - 1; j++){
        		row.push_back(triangle[i-1][j] + triangle[i-1][j+1]);
        	}
        	row.push_back(1);
        	triangle.push_back(row);
        }
        return triangle;
    }
};

int main(){
	Solution s;
	vector< vector<int> > triangle;
	triangle = s.generate(5);
	for(int i = 0; i < triangle.size(); i++){
		for(int j = 0; j < triangle[i].size(); j++){
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}