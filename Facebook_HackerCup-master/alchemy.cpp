#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,temp=1;
    long int n;
    string str;
    cin>>tc;
    while(temp<=tc)
    {
        cin>>n;
        cin>>str;
        long int cntA=0,cntB = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='A')
                cntA++;
            else if(str[i]=='B')
                cntB++;
        }

        if(abs(cntA-cntB)==1)
        {
            int j,siz;
            siz = str.size();
            //Now check if we can get the sequence such that no three are alike
            for(int i=0;i<siz-2;i++)
            {
                if(i>=siz-2)
                    break;
                cntA = 0;
                cntB = 0;
                if(i<0)
                    i=0;
                if(i<siz-2)
                {
                    j= i;
                    while(j<=i+2)
                    {
                        if(str[j]=='A')
                            cntA++;
                        else
                            cntB++;
                        j++;
                    }
                    if(abs(cntA-cntB)==1)
                    {
                        str.erase(i,3);
                        if(cntA>cntB)
                        {
                            str.insert(i,"A");
                        }
                        else
                            str.insert(i,"B");
                        i-=3;
                        siz-=2;
                    }
                }
                else
                    break;
            }
            cout<<"Case #"<<temp<<": ";
            if(str.size()==1)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;

        }
        else
        {
            cout<<"Case #"<<temp<<": ";
            cout<<"N"<<endl;
        }

        temp++;
    }

    return 0;
}
