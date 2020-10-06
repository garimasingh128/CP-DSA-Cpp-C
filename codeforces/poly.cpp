#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a<=b)
		{
			cout<<b<<endl;
		}
		if(a>b && c<=d)
		{
			cout<<-1<<endl;
		}
		if(a>b && c>d)
		{
			float i;
			long long int r;
			long long int n=a-b;
			long long int m=c-d;
			if(n%m==0)
			{
				i=n/m;
				r=b+c*i;
			}
			else 
			{
				i=n/m;
				r=b+c*ceil(i);
			}
			cout<<r<<endl;
		}
	}
}
