class Solution {
public:
    bool backspaceCompare(string S, string T) {

        int s_p=S.length()-1;
        int t_p=T.length()-1;
        int s_s=0;
        int t_s=0;
        while(s_p>=0 || t_p>=0)
        {
            while(s_p>=0)
            {
                if(S[s_p]=='#')
                {
                    s_p--;
                    s_s++;
                }
                else if(S[s_p]!='#' && s_s>0)
                {
                    s_p--;
                    s_s--;
                }
                else
                    break;
            }
            while(t_p>=0)
            {
                if(T[t_p]=='#')
                {
                    t_p--;
                    t_s++;
                }
                else if(T[t_p]!='#' && t_s>0)
                {
                    t_p--;
                    t_s--;
                }
                else
                    break;
            }
            if(s_p>=0 && t_p>=0 && S[s_p]!=T[t_p])
                return false;
            if((s_p>=S.length())!=(t_p>=T.length()))
                return false;
            s_p--;
            t_p--;
        }
        return true;

    }
};
