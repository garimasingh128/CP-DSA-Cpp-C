#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int x,y,a,b,n;
	cin>>x>>y>>a>>b;
	float m=(float)(y-x)/(float)(a+b);
	if(floor(m)==ceil(m))
	{
		n=(int)m;
		cout<<n<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	}
	return 0;
}
