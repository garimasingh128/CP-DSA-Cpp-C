class Solution {
public:
    bool backspaceCompare(string s, string t) {
    int x,n,i,j;
    int m;
    m=t.length();
    n=s.length();
   for(i=0;i<n;i++)
    {
        if(s[0]=='#')
        {
            for(j=0;j<n;j++)
            {
                s[j]=s[j+1];
            }
            n--;
        }
        if(s[i]=='#'&&i!=0)
        {
            x=i;
            for(j=i-1;j<n-2;j++)
            {
                s[j]=s[j+2];
            }
            i=x-2;
            n=n-2;
        }
    }
    if(s[0]=='#')
        {
            for(j=0;j<n;j++)
            {
                s[j]=s[j+1];
            }
            n--;
        }
    for(i=0;i<m;i++)
    {
        if(t[0]=='#')
        {
            for(j=0;j<m;j++)
            {
                t[j]=t[j+1];
            }
            m--;
        }
        if(t[i]=='#'&&i!=0)
        {
            x=i;
            for(j=i-1;j<m-2;j++)
            {
                t[j]=t[j+2];
            }
            i=x-2;
            m=m-2;
        }

    }
    if(t[0]=='#')
        {
            for(j=0;j<m;j++)
            {
                t[j]=t[j+1];
            }
            m--;
        }
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(s[i]==t[i])
            continue;
        else
        {flag=1;
        break;
        }
    }
    if(flag==1||m!=n)
        return false;
    else
        return true;
        
    }
};