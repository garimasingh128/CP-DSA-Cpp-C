#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c=0;
	cin>>n;
	vector<int> d;
	for(int i=0;i<n;i++)
	{
		int d1;
		cin>>d1;
		d.push_back(d1);
	}
	sort(d.begin(),d.end());
	for(int j=0;j<n-1;j=j+2)
	{
		c=c+d.at(j+1)-d.at(j);
	}
	cout<<c;
}
