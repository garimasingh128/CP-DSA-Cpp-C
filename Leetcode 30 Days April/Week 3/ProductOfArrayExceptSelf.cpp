class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        int n=nums.size(),r;
        vector<int> f(n,0);
        int i;
        f[0]=1;
        for(i=1;i<nums.size();i++)
            f[i]=f[i-1]*nums[i-1];
        r=1;
        for(i=n-1;i>=0;i--)
        {
            f[i]=f[i]*r;
            r*=nums[i];
        }
        return f;

    }
};
