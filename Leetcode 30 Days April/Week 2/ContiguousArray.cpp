class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int i,maxi=-1,c=0;
        unordered_map<int,int> m;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                c++;
            else
                c--;
            if(c==0)
                maxi=max(i+1,maxi);
            if(m.find(c)!=m.end())
            {
                maxi=max(i-m[c],maxi);
            }
            else if(m.find(c)==m.end())
                m[c]=i;
        }
        return maxi>0?maxi:0;

    }
};
