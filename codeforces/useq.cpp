#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		long long int s=0;
		for(int i=1;i<=n;i++)
		{
			long long int p=1;
			for(int j=0;j<=k;j++)
			{
				p=p*(i+j);
			}
			s=s+p;
		}
		cout<<s;
	}
}
