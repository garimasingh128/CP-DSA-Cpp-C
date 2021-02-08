class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int i,s=0,r=0;
        for(i=digits.size()-1;i>=0;i--)
        {
            if(i==digits.size()-1)
                s=digits[i]+r+1;
            else
                 s=digits[i]+r;


            r=s/10;
            s=s%10;

            digits[i]=s;

        }
        if(r!=0)
            digits.insert(digits.begin(),r);

        return digits;

    }
};
