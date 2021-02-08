class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int i,j;
        vector<vector<int> > dp(grid.size(),vector<int>(grid[0].size(),0));
        for(i=0;i<dp.size();i++)
        {
            for(j=0;j<dp[0].size();j++)
            {
                dp[i][j]+=grid[i][j];
                if(i>0 && j>0)
                    dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
                else if(i>0)
                    dp[i][j]+=dp[i-1][j];
                else if(j>0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];


    }
};
