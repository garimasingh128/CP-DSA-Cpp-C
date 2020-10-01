class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        if (dungeon.empty() || dungeon[0].empty()) return 0;  // invalid

        int rows = dungeon.size(), cols = dungeon[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i=rows-1; i >= 0; --i)
        {
            for (int j=cols-1; j >= 0; --j)
            {
                if (i == rows - 1 && j == cols - 1)
                    dp[i][j] = min(0, dungeon[i][j]);
                else if (i == rows - 1)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                else if (j == cols - 1)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                else
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j+1], dp[i+1][j]));
            }
        }
        return -dp[0][0] + 1;
    }
};
