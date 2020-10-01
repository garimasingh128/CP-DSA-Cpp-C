#include <bits/stdc++.h>
#define int long long int 
using namespace std;

// Author: Ashish

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  for(int _=1;_<=t;_++)
  {
  	cout<<"Case #"<<_<<": ";
  	int n,d;
  	cin>>n>>d;
  	vector<int> input(n);
  	for(auto&itr:input) cin>>itr;
  	for(int i=n-1;i>=0;i--)
  	{
  		d=d-d%input[i];
  	}
  	cout<<d<<'\n';


  }	
  

 	return 0;
}