#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,f=0;
	cin>>w;
	for(int i=1;i<=w;i++)
	{
		int j=w-i;
		if(i%2==0 && j%2==0 && j!=0)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}
