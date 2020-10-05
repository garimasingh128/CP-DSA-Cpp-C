#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	int n,t;
	vector<int> v1;
	cin>>t;
	while(t--){
	cin>>n;
	for (int x=1;x<n;x++)
	{
		double m=((n/x)+1);
		double k;
		k=log2(m);
		if(ceil(k)==k && floor(k)==k)
		{
			v1.push_back(x);
		}	
	}
		cout<<v1.back()<<endl;
	
}}
