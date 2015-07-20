#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        vector<int> result;
        if(matrix.size() == 0){
            return result;
        }
        vector< vector<bool> > record(matrix.size(),vector<bool>(matrix[0].size(),false));
        int tag = 1;
        int i = 0, j = 0;
        int rowLength = matrix.size();
        int columnLength = matrix[0].size();
        result.push_back(matrix[0][0]);
        record[0][0] = true;
        while(true){
            if(tag == 1){
                if(j + 1 == columnLength || record[i][j+1]){
                    tag = 2;
                }else{
                    result.push_back(matrix[i][j+1]);
                    record[i][j+1] = true;
                    j++;
                }
                if(tag == 2 && (i + 1 == rowLength || record[i+1][j])){
                    return result;
                }
            }
            if(tag == 2){
                if(i + 1 == rowLength || record[i+1][j]){
                    tag = 3;
                }else{
                    result.push_back(matrix[i+1][j]);
                    record[i+1][j] = true;
                    i++;
                }
                if(tag == 3 && (j - 1 < 0 || record[i][j-1])){
                    return result;
                }
            }
            if(tag == 3){
                if(j == 0 || record[i][j-1]){
                    tag = 4;
                }else{
                    result.push_back(matrix[i][j-1]);
                    record[i][j-1] = true;
                    j--;
                }
                if(tag == 4 && (i - 1 < 0 || record[i-1][j])){
                    return result;
                }
            }
            if(tag == 4){
                if(i == 0 || record[i-1][j]){
                    tag = 1;
                }else{
                    result.push_back(matrix[i-1][j]);
                    record[i-1][j] = true;
                    i--;
                }
                if(tag == 1 && (j + 1 == columnLength || record[i][j+1])){
                    return result;
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector< vector<int> > v;
    vector<int> row;
    row.push_back(1);
    row.push_back(2);
    row.push_back(3);
    v.push_back(row);
    row.clear();
    
    row.push_back(4);
    row.push_back(5);
    row.push_back(6);
    v.push_back(row);
    row.clear();

    row.push_back(7);
    row.push_back(8);
    row.push_back(9);
    v.push_back(row);
    row.clear();

    row.push_back(10);
    row.push_back(11);
    row.push_back(12);
    v.push_back(row);
    row.clear();
    
    row = s.spiralOrder(v);
    for(int i = 0; i < row.size(); i++){
        cout<<row[i]<<endl;
    }
    return 0;
}