class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

      if(nums.size()<1)
          return 0;

      int l=0,m,pos;
      int h=nums.size()-1;
      while(l<=h)
      {
          m=l+(h-l)/2;

          if(nums[m]==target)
              return m;
          else if(nums[m]>target)
          {
              pos=m;
              h=m-1;
          }
          else
          {
              pos=m+1;
              l=m+1;
          }
      }

      return pos;
    }
};
