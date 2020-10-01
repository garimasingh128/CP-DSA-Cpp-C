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
  	int n;
  	cin>>n;
  	vector<int> input(n);
  	for(auto&itr:input) cin>>itr;
  	int answer=0;
  	for(int i=1;i<n-1;i++)
  	{
  		if(input[i]>input[i-1]&&input[i]>input[i+1]) answer++;
  	}
  	cout<<answer<<'\n';


  }	
  

 	return 0;
}