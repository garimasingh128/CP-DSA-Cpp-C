#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		vector<int> d;
		cin>>n>>k;
		for(int i=0;i<=k;i++)
		{
			for(int j=2;j<=n/2;j++)
			{
				if(n%j==0)
				{
					for(int k=0;k<=(n/2-2);k++){
					d.push_back(j);}
				}
			}
			n=n+d.at(0);
		}
		cout<<n<<endl;
	}
}
