#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a2,a3,a5,a6,b,c,d;
	cin>>a2>>a3>>a5>>a6;
	b=min(a2,min(a5,a6));
	a2=a2-b;
	a5=a5-b;
	a6=a6-b;
	c=min(a2,a3);
	d=(b*256)+(c*32);
	cout<<d;
}
