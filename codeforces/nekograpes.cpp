#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a;
	vector<int> b;
	int n,m,ad,bd,count=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ad;
		a.push_back(ad);
	}
	for(int j=1;j<=m;j++)
	{
		cin>>bd;
		b.push_back(bd);
	}
	for(int x=0;x<a.size();x++)
	{
		for(int y=0;y<b.size();y++)
		{
			if((a[x]+b[y])%2==1)
			{
				count++;
				a.erase(a.begin()+x);
				b.erase(b.begin()+y);
			}
		}
	}
	cout<<count;
}
