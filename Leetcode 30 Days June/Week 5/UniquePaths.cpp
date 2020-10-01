class Solution {
public:
    int uniquePaths(int m, int n) {

        if(m==1 || n==1)
            return 1;

        int i,j;
        vector<vector<int>> v(n+1,vector<int>(m+1,0));

        v[1][1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(n==1 && m==1)
                    continue;
                v[i][j]+=v[i-1][j]+v[i][j-1];
            }
        }
        return v[n][m];
    }
};
