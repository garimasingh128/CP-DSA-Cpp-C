class Solution {
public:
    int msb(int n)
    {
        int msbp=-1;
        while(n)
        {
            n=n>>1;
            msbp++;
        }
        return msbp;
    }
    int rangeBitwiseAnd(int m, int n) {

        int msbm,msbn;
        int f=0;
        while(m && n)
        {
            msbm=msb(m);
            msbn=msb(n);

            if(msbm!=msbn)
                break;
            f+=1<<msbm;
            m-=1<<msbm;
            n-=1<<msbm;
        }
        return f;
    }
};
