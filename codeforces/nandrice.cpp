#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int diff=a-b;
		int sum=a+b;
		int t1=n*diff;
		int t2=n*sum;
		int td=c-d;
		int ts=c+d;
		if((t1>=td && t1<=ts)||(t2>=td && t2<=ts)||(t1<=td && t2>=ts))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
