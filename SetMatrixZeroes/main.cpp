#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        set<int> rows,columns;
        for(int i = 0; i < matrix.size(); i++){
        	for(int j = 0; j < matrix[i].size(); j++){
        		if(matrix[i][j] == 0){
        			rows.insert(i);
        			columns.insert(j);
        		}
        	}
        }

        for(set<int>::iterator sii = rows.begin(); sii != rows.end(); sii++){
        	for(int j = 0; j < matrix[*sii].size(); j++){
        		matrix[*sii][j] = 0;
        	}
    	}

    	for(set<int>::iterator sii = columns.begin(); sii != columns.end(); sii++){
        	for(int i = 0; i < matrix.size(); i++){
        		matrix[i][*sii] = 0;
        	}
    	}
    }
};

int main(){
	vector< vector<int> > matrix;
	vector<int> row;
	Solution s;
	row.push_back(0);
	row.push_back(2);
	row.push_back(1);
	matrix.push_back(row);
	row.clear();
	row.push_back(1);
	row.push_back(3);
	row.push_back(0);
	matrix.push_back(row);

	s.setZeroes(matrix);
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}