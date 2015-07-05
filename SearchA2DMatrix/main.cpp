#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int columnLength = matrix.size();
        int low = 0, high = columnLength - 1,mid = 0,row;

        if(matrix.size() == 0){
        	return false;
        }

        while(low <= high){
        	mid = (low + high) / 2;
        	if(matrix[mid][0] == target){
        		return true;
        	}
        	if(matrix[mid][0] < target){
        		int rowLength = matrix[mid].size();
        		if(matrix[mid][rowLength-1] >=target){
        			break;
        		}else{
        			low = mid + 1;
        		}
        	}else{
        		// > target
        		if(mid - 1 >= 0){
        			if(matrix[mid - 1][0] <= target){
        				mid = mid - 1;
        				break;
        			}else{
        				high = mid - 1;
        			}
        		}else{
        			return false;
        		}
        	}
        }
        row = mid;
        low = 0;
        high = matrix[row].size();
        while(low <= high){
        	mid = (low + high) / 2;
        	if(matrix[row][mid] == target){
        		return true;
        	}
        	if(matrix[row][mid] < target){
        		low = mid + 1;
        	}else{
        		high = mid - 1;
        	}
        }
        return false;
    }
};

int main(){
	Solution s;
	vector< vector<int> > matrix;
	vector<int> row;
	row.push_back(1);
	row.push_back(3);
	row.push_back(5);
	row.push_back(7);
	matrix.push_back(row);
	row.clear();

	row.push_back(10);
	row.push_back(11);
	row.push_back(16);
	row.push_back(20);
	matrix.push_back(row);
	row.clear();

	row.push_back(23);
	row.push_back(30);
	row.push_back(34);
	row.push_back(50);
	matrix.push_back(row);
	row.clear();

	cout<<s.searchMatrix(matrix, 10)<<endl;
	return 0;
}