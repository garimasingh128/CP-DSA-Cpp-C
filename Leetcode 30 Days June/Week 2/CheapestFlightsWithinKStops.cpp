class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));


        for(int i = 0; i <= K+1; i++)
        {
            dp[i][src] = 0;
        }

        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                int u = f[0];
                int v = f[1];
                int w = f[2];

                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }

        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];

    }
};
