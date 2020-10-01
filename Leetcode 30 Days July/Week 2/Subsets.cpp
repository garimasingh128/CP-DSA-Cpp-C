class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> f;
        int n,i,j,t,m;
        m=nums.size();
        for(i=0;i<(1<<m);i++)
        {
            j=0;
            n=i;
            vector<int> v;
            while(n!=0)
            {
                t=n&1;
                if(t)
                    v.push_back(nums[j]);
                j++;
                n=n>>1;
            }
            f.push_back(v);
        }
        return f;
    }
};
