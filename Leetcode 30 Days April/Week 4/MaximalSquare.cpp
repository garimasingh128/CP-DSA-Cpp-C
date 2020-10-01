class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {


        int n,m,maxi=0,i,j;
        n=matrix.size();
         if(n==0)
            return 0;
        m=matrix[0].size();
        vector<vector<int> > a(n+1,vector<int> (m+1,0));

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    a[i][j]=1+min(a[i-1][j],min(a[i-1][j-1],a[i][j-1]));
                }
                maxi=max(a[i][j],maxi);
            }
        }
        return maxi*maxi;

    }
};
