#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[2],i,j,k,d=0,m,x,immunity=0;
	for(k=0;k<2;k++)
	{
		cin>>arr[k];
	}
	int n = sizeof(arr)/sizeof(arr[0]); 
    sort(arr, arr+n);
    d=arr[1]-arr[0];
    if(d%2==0)
    {
    	m=d/2;
    	for(i=1;i<=m;i++)
    	{
    		immunity=immunity+i;
		}
		immunity=immunity*2;
	}
	else
	{
		x=d-1;
		x=x/2;
		for(j=1;j<=x;j++)
		{
			immunity=immunity+j;
		}
		immunity=2*immunity+x+1;
	}
	cout<<immunity;
}
