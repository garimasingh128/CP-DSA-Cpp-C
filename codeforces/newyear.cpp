#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,t=0,q=0;
	cin>>n>>k;
	int tt=240;
	int rt=240-k;
	for(int i=1;i<=n;i++)
	{
		t=t+5*i;
		if(t>rt)
		{
			break;
		}
		q++;
	}
	cout<<q;
}
