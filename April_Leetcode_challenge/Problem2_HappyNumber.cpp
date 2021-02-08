class Solution {
public:
    bool isHappy(int n) {
    int i,sum=0,x;
        set <int> st;
    for(i=0;;i++)
    {
        sum=0;
        st.insert(n);
        while(n!=0)
        {
            x=n%10;
            n/=10;
            sum+=x*x;
        }
        if(sum==1)
            break;
        else
        {
            n=sum;
        }
        if(st.find(n)!=st.end())
            return false;
    }
    if(sum==1)
        return true;
    return false;
    }
};