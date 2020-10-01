class Solution {
public:
    void moveZeroes(vector<int>& a) {
        long i,n,k=0;
        n=a.size();
        vector <int> b;
        if(n==1)
            return;
        for(i=0;i<n;i++)
        {           
           if(a[i]!=0)
               a[k++]=a[i];
        }
        for(i=k;i<n;i++)
            a[i]=0;
        
        
    }
};