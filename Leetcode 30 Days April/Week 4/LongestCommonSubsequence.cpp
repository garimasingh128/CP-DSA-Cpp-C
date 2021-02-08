class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int i,j;
        int n=text1.length();
        int m=text2.length();
        int a[n+1][m+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    a[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    a[i][j]=1+a[i-1][j-1];
                else
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
        return a[n][m];

    }
};
