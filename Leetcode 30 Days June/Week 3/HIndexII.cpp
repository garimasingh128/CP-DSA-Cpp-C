class Solution {
public:
    int hIndex(vector<int>& citations) {

        int i=0,j,n,m;
        n=citations.size();
        j=n-1;
        while(i<=j)
        {
            m=i+(j-i)/2;
            if(m+citations[m]>=n)
                j=m-1;
            else
                i=m+1;
        }
        return n-i;
    }
};
