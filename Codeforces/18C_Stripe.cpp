#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll a[n],sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    ll ans=0,sum1=0;
    for(ll i=0;i<n-1;i++){
        sum1+=a[i];
        sum-=a[i];
        if(sum1==sum)
            ans++;
    }
    cout<<ans;
  return 0;
}
