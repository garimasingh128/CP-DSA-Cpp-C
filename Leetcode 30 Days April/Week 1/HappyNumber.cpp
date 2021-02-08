class Solution {
public:
    bool isHappy(int n) {

        int t,s,d;
        while(1)
        {
            t=n;
            s=0;
            while(t!=0)
            {
                d=t%10;
                t=t/10;
                s+=d*d;
            }
            if(s==1)
                return true;
            else if(s==4 || s==16 ||s==37 ||s==58 ||s==89 ||s==145 ||s==42 ||s==20)
                return false;
            else
            {
                n=s;
            }
        }

    }
};
