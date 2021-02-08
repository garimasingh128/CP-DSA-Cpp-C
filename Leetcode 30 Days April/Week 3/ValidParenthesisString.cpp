class Solution {
public:
    bool checkValidString(string s) {

        int i,x,y;
        stack<int> open;
        stack<int> a;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                a.push(i);
            else
            {
                if(open.empty())
                {
                    if(a.empty())
                        return false;
                    else
                        a.pop();
                }
                else
                    open.pop();
            }
        }
        while(!open.empty())
        {
            if(a.empty())
                return false;
            else
            {
                x=open.top();
                y=a.top();
                if(y<=x)
                    return false;
                a.pop();
                open.pop();
            }
        }
        return true;
    }
};
