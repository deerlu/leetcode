#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
    	vector< vector<int> > matrix(n,vector<int>(n));
    	int i = 0,j = 0,number = 2,direction = 1;
        if(n == 0) return matrix;
    	matrix[0][0] = 1;
    	while(true){
    		if(direction == 1 && j+1 < n && matrix[i][j+1] == 0){
    			//right
    			matrix[i][j+1] = number++;
    			j++;
    			continue;
    		}else{
    			direction = 2;
    		}
    		if(direction == 2 && i+1 < n && matrix[i+1][j] == 0){
    			//down
    			matrix[i+1][j] = number++;
    			i++;
    			continue;
    		}else{
    			direction = 3;
    		}
    		if(direction == 3 && j-1 >= 0 && matrix[i][j-1] == 0){
    			//left
    			matrix[i][j-1] = number++;
    			j--;
    			continue;
    		}else{
    			direction = 4;
    		}
    		if(direction == 4 && i-1 >= 0 && matrix[i-1][j] == 0){
    			//up
    			matrix[i-1][j] = number++;
    			i--;
    			continue;
    		}else{
    			direction = 1;
    		}
    		
    		if((direction == 1 && (j + 1 >= n || matrix[i][j + 1] != 0))
            || (direction == 2 && (i + 1 >= n || matrix[i + 1][j] != 0))
            || (direction == 3 && (j - 1 < 0 || matrix[i][j - 1] != 0))
            || (direction == 4 && (i - 1 < 0 || matrix[i - 1][j] != 0))){
                break;
            }
    	}
    	return matrix;
        
    }
};

int main(){
	vector< vector<int> > matrix;
	Solution s;
	matrix = s.generateMatrix(2);
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}