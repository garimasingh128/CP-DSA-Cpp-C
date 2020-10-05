#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[105];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}
