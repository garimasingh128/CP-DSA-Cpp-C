#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    long long int x,y,z,a,b,c;
    while(t--)
    {
        cin>>x>>y>>a>>b;
        z=y-x;
        c=a+b;
        if(z%c==0)
            cout<<z/c<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}

