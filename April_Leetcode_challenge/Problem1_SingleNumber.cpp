class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long int i,j,flag;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-1;)
        {
           if(nums[i]==nums[i+1])
               i+=2;
            else
                break;
            
        }
        return nums[i];
    }
};