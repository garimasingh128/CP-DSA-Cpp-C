class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,s=0,maxi=INT_MIN;

        for(i=0;i<nums.size();i++)
        {
            s+=nums[i];
            maxi=max(s,maxi);
            if(s<0)
                s=0;
        }
        return maxi;
    }
};
