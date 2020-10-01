class Solution {
public:
    vector<int>dp;
    int numTrees(int n) {
        dp.resize(n+1);
        fill_n(dp.begin(),n+1,0);
        dp[0]=1;
        dp[1]=1;
       return noOfUniqueBST(n);
    }
    int noOfUniqueBST(int n)
    {
        int count=0;
        for(int i=1;i<=n;i++)
        {
        if(dp[i-1]==0)
            dp[i-1]=noOfUniqueBST(i-1);
        if(dp[n-i]==0)
            dp[n-1]=noOfUniqueBST(n-i);
        count+=dp[i-1]*dp[n-i];
        }
        return count;
    }
};
