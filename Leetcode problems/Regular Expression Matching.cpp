#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length()+1;
        int lp = p.length()+1;
        s.insert(0,"#");
        p.insert(0,"#");
        vector<vector<int>> dp(lp,vector<int>(ls));
        for(int i = 0;i<lp;i++){
            for(int j = 0;j<ls;j++){
                int flag = (i>0) && (j>0) ? dp[i-1][j-1] : ((i<1) && (j<1) ? 1 : 0);
                if(flag){
                    if(p[i]=='.'||p[i]==s[j]) dp[i][j] = 1;
                    else if(p[i]=='*'){
                        if(i>1&&dp[i-2][j]) dp[i][j] = 1;
                        else if(j>0 && (p[i-1]=='.'||s[j]==p[i-1])) dp[i][j] = 1;
                    }
                }
                else{
                    if(p[i]=='*'){
                        if(i>1 && dp[i-2][j]) dp[i][j] = 1;
                        else if(j>0 && (p[i-1]=='.'||s[j]==p[i-1]) && dp[i][j-1]) dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[lp-1][ls-1];
    }
};