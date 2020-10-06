#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int c=0,i;
    string s,s1;
    cin>>s;
    for(i=0; i<5; i++)
    {
        cin>>s1;
        if((s[0]==s1[0])||(s[1]==s1[1]))
            c++;
    }
    if(c>0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

