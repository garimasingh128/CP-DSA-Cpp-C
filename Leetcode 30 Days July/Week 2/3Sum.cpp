class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int i,l,r;
        set<vector<int> > s;
        vector<vector<int> > v;
        if(nums.empty())
            return v;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-1;i++)
        {
            l=i+1;
            r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0)
                {
                   l++;
                }
                else
                    r--;
            }
        }
        for(auto j:s)
        {
            v.push_back(j);
        }
        return v;
    }
};
