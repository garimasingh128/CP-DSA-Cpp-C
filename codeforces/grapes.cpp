#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,g,p,b,r,s;
	cin>>x>>y>>z;
	cin>>g>>p>>b;
	if(g>=x)
	{
		r=g-x;
		if((r+p)>=y)
		{
			s=g+p-x-y;
			if((s+b)>=z)
			{
				cout<<"YES";
			}
			else{cout<<"NO";
			}
		}
		else{cout<<"NO";
		}
	}
	else{cout<<"NO";
	}
}
