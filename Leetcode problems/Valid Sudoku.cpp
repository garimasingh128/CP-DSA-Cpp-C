#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10,0));
        vector<vector<int>> col(9, vector<int>(10,0));
        vector<vector<int>> boxs(9, vector<int>(10,0));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                int box = (i/3) * 3 + j/3;
                if(row[i][num] != 0) return false;
                if(col[j][num] != 0) return false;
                if(boxs[box][num] != 0) return false;
                row[i][num] = 1;
                col[j][num] = 1;
                boxs[box][num] = 1;   
            }
        }
        return true;
    }
};