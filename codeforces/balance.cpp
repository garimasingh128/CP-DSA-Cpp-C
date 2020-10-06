#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,r=0,a=0,b=0,as=0,bs=0;
		cin>>n;
		for(int i=n/2;i<n;i++)
		{
			b=(int)(pow(2,i)+0.5);
			bs=bs+b;
		}
		for(int i=1;i<n/2;i++)
		{
			a=(int)(pow(2,i)+0.5);
			as=as+a;
		}
		r=as+(int)(pow(2,n)+0.5)-bs;
		cout<<r<<endl;
	}
}
