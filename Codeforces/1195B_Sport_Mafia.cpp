#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while(t-->0){
        ll n;
        cin>>n;
        ll ans=0;
        while(n>0){
            ll temp=log2(n);
            n-=pow(2,temp);
            if(n>=0)
                ans++;
        }
        cout<<ans;
    }

  return 0;
}
