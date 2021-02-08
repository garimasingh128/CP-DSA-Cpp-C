//https://www.codechef.com/LRNDSA02/problems/STFOOD
#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int profit=0;
		while(n--)
		{
			int s,p,v;
			cin>>s>>p>>v;
			int new_profit=(p/(s+1))*v;
			if(new_profit>profit)
				profit=new_profit;
		}

		cout<<profit<<'\n';
	}
}