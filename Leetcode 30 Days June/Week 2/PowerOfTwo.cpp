class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<0)
            return false;
        int c=0;
        while(n)
        {
            n=(n)&(n-1);
            c++;
        }
        if(c==1)
            return true;
        else
            return false;
    }
};
