class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        int m=amount;
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
            t[i][0]=1;
        for(int i=1;i<=m;i++)
            t[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(coins[i-1]<=j)
                    t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][m];

    }
};
