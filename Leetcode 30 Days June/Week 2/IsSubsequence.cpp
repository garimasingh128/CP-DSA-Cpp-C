class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i,j,c=0;
        i=0;
        j=0;
        while(i<s.length() && j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                c++;

            }
            else
                j++;
        }
        //cout << c;
        if(c==s.length())
            return true;
        else
            return false;
    }
};
