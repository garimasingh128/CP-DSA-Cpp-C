#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	long int xor_arr = 0; 
	cin>>c;
	cout<<c<<endl;
	int n,q,d;
	vector<long int>a;
	vector<long int>b;
	cin>>n>>q;
	for(int i=0;i<q;i++)
	{
		cin>>d;
		a.push_back(d);
	}
	while(n--)
	{
		for (int i=0;i<a.size();i++)
		{
			b.push_back(a.at(i));
		}
	}
	for(int i=0;i<b.size();i++)
	{
		xor_arr=xor_arr ^ b.at(i);
	}
	cout<<xor_arr<<endl;
}
