class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int i,j,s,f=0;
        for(i=0;i<32;i++)
        {
            s=0;
            for(j=0;j<nums.size();j++)
            {
                if(nums[j]&(1<<i))
                    s++;
            }
            if(s%3!=0)
            {
                f|=(1<<i);
            }
        }
        return f;
    }
};
