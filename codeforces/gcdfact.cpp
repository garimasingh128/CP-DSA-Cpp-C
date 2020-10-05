#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,i,ans=1;
    cin>>a>>b;
    for(i=1;i<=min(a,b);i++)
    {
            ans*=i;
    }
    cout<<ans<<endl;
    return 0;
}
