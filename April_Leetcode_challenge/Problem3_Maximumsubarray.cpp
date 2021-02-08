class Solution {
public:
    int maxSubArray(vector<int>& a) {
        long int i,n;
        long int sum=-10000000000;
        n=a.size();
        long int m=0;
        for(i=0;i<n;i++)
        {
            m=m+a[i];
            if(m>sum)
                sum=m;
            if(m<0)
                m=0;
        }
        return sum;
    }
};