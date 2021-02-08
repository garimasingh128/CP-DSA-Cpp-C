#include <bits/stdc++.h>
#define int long long int 
using namespace std;

// Author: Ashish

#define MAX 200001 
long double dp[MAX]; 

long double probability(int k, int n) 
{ 
  // cout<<k<<' '<<n<<'\n';
  long double ans = 0; 
  for (int i=k; i <= n; ++i) 
  { 
    long double res = dp[n] - dp[i] - dp[n-i] - n; 
    ans += pow(2.0, res); 
  } 
  return ans; 
} 
void precompute() 
{ 
  for (int i=2; i < MAX; ++i) 
    dp[i] = log2(i) + dp[i-1]; 
} 




int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  precompute();
  int t;
  cin>>t;
  for(int _=1;_<=t;_++)
  {
    cout<<"Case #"<<_<<":   ";
    int u,d,h,l,r,w;
    cin>>w>>h>>l>>u>>r>>d;
    if(l==1&&r==w) {cout<<"0.0\n"; continue;}
    if(u==1&&d==h) {cout<<"0.0\n"; continue;}
    long double ans=(r!=w?probability(r,r+u-2):0)+(d!=h?probability(d,d+l-2):0);
    cout<<ans<<'\n';

  } 
  

    return 0;
}