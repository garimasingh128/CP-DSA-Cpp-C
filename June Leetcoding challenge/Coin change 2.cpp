class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=amount;j++){
                if(j>=coins[i-1]) dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};
