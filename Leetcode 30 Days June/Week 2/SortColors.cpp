class Solution {
public:
    void sortColors(vector<int>& nums) {


         int i=0,e=nums.size()-1,s=0;
        while(s<e && i<=e)
        {
            if(nums[i]==0)
            {
                nums[i]=nums[s];
                nums[s]=0;
                s++;
                i++;
            }
            else if(nums[i]==2)
            {
                nums[i]=nums[e];
                nums[e]=2;
                e--;
            }
            else
                i++;
        }

    }
};
