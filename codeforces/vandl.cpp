#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l;
	cin>>n>>l;
	int a1[n],a2[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a1[i];
	}
	int m = sizeof(a1)/sizeof(a1[0]); 
  
    sort(a1, a1+m);
    a2[0]=a1[0];
    for(int i=1;i<n;i++)
    {
    	a2[i]=(a1[i]-a1[i-1])/2
	}
	a2[n]=l-a1[n-1];
	
}
