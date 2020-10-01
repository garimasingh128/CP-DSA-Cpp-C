class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {


        int n=nums.size();
        if(n==0)
            return {};

        sort(nums.begin(),nums.end());
        vector<pair<int,int> > dp(n);
        int en=0,maxi=1;

        for(int i=0;i<n;i++)
            dp[i]={1,i};

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j].first+1>dp[i].first)
                {
                    dp[i].first=dp[j].first+1;
                    dp[i].second=j;

                    if(dp[i].first>maxi)
                    {
                        maxi=dp[i].first;
                        en=i;
                    }
                }
            }
        }
        vector<int> ans;
        int i=en;
        while(i>=0)
        {
            ans.push_back(nums[i]);

            if(dp[i].second==i)
                break;

            i=dp[i].second;
        }
        return ans;
    }
};
