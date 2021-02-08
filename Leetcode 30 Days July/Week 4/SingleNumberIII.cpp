class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int i,x,a=0,b=0,sb;
        vector<int> v;
        x=nums[0];
        for(i=1;i<nums.size();i++)
        {
            x^=nums[i];
        }
        sb=x & ~(x-1);
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]&sb)
                a^=nums[i];
            else
                b^=nums[i];
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};
