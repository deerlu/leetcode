#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        int tmp,n;
        vector< vector<int> > result(matrix);
        n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                result[j][n-i-1] = matrix[i][j];
            }
        }
        matrix = result;
    }
};

int main()
{
    Solution s;
    vector< vector<int> > matrix;
    vector<int> row;
    row.push_back(1);
    row.push_back(2);
    row.push_back(3);
    row.push_back(4);
    matrix.push_back(row);
    row.clear();
    row.push_back(5);
    row.push_back(6);
    row.push_back(7);
    row.push_back(8);
    matrix.push_back(row);
    row.clear();
    row.push_back(9);
    row.push_back(10);
    row.push_back(11);
    row.push_back(12);
    matrix.push_back(row);
    row.clear();
    row.push_back(13);
    row.push_back(14);
    row.push_back(15);
    row.push_back(16);
    matrix.push_back(row);

    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
