#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i=0;i<N/2;i++) { 
            for (int j=i;j<N-i-1;j++) { 
                int temp=matrix[i][j]; 
                matrix[i][j] = matrix[N-1-j][i]; 
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j]; 
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i]; 
                matrix[j][N-1-i] = temp; 
            } 
        } 
    }
};