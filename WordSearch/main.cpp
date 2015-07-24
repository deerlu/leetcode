#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int wordPos;
    string word;
    vector< vector<bool> > hasTouched;
    vector< vector<char> > myboard;
    int row;
    int column;
    
    bool searchWord(int x, int y){
        if(wordPos == word.size()){
            return true;
        }
        
        //left
        if(y-1 >= 0 && !hasTouched[x][y-1] && word[wordPos] == myboard[x][y-1]){
            wordPos++;
            hasTouched[x][y-1] = true;
            if(searchWord(x,y-1)){
                return true;
            }
            wordPos--;
            hasTouched[x][y-1] = false;
        }
        
        
        //right
        if(y+1 < column && !hasTouched[x][y+1] && word[wordPos] == myboard[x][y+1]){
            wordPos++;
            hasTouched[x][y+1] = true;
            if(searchWord(x,y+1)){
                return true;
            }
            wordPos--;
            hasTouched[x][y+1] = false;
        }
        
        
        //up
        if(x-1 >= 0 && !hasTouched[x-1][y] && word[wordPos] == myboard[x-1][y]){
            wordPos++;
            hasTouched[x-1][y] = true;
            if(searchWord(x-1,y)){
                return true;
            }
            wordPos--;
            hasTouched[x-1][y] = false;
        }
        
        
        //down
        if(x+1 < row && !hasTouched[x+1][y] && word[wordPos] == myboard[x+1][y]){
            wordPos++;
            hasTouched[x+1][y] = true;
            if(searchWord(x+1,y)){
                return true;
            }
            wordPos--;
            hasTouched[x+1][y] = false;
        }
        
        return false;
    }
    
public:
    bool exist(vector< vector<char> >& board, string word) {
        wordPos = 0;//正在比较的字符
        this->word = word;
        if(board.size() == 0 || board[0].size() == 0){
            return false;
        }
        row = board.size();
        column = board[0].size();
        hasTouched.resize(row,vector<bool>(column));
        myboard = board;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(board[i][j] == word[wordPos]){
                    for(int m = 0; m < row; m++){
                        for(int n = 0; n < column; n++){
                            hasTouched[m][n] = false;
                        }
                    }
                    wordPos++;
                    hasTouched[i][j] = true;
                    if(searchWord(i,j)){
                        return true;
                    }else{
                        wordPos--;
                    }
                }
            }
        }
        return false;
        
    }
};

int main(){
    Solution s;
    vector< vector<char> > v;
    vector<char> row;
    row.push_back('A');
    row.push_back('B');
    row.push_back('C');
    row.push_back('E');
    v.push_back(row);
    row.clear();
    
    row.push_back('S');
    row.push_back('F');
    row.push_back('C');
    row.push_back('S');
    v.push_back(row);
    row.clear();
    
    row.push_back('A');
    row.push_back('D');
    row.push_back('E');
    row.push_back('E');
    v.push_back(row);
    row.clear();
    
    cout<<s.exist(v,"ABCB")<<endl;
    return 0;
}