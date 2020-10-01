#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++)
      cin>>a[i];
  sort(a,a+n);
  ll temp=1;
  for(ll i=0;i<n;i++)
      if(a[i]>=temp)
          temp++;
  cout<<temp-1;
  return 0;
}
