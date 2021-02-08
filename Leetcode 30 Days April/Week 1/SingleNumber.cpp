class Solution {
public:
    int singleNumber(vector<int>& nums)
    {

        int i,p=0;
        for(i=0;i<nums.size();i++)
        {
            p^=nums[i];
        }
        return p;

    }
};
