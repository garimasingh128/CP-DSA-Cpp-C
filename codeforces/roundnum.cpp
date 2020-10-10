#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,c=0;
	cin>>t;
	while(t--)
	{
		int n;
		vector<int> num;
		cin>>n;
		while(n!=0)
		{
			int d=n%10;
			num.push_back(d);
			n=n/10;
		}
		for (int it = 0; it != num.size(); it++)
		{
			if(num.at(it)==0)
			{
				c++;
			}
		}
		cout<<num.size()-c<<endl;
		for (int it = 0; it != num.size(); it++)
		{
        if(num.at(it)!=0)
		{
			cout<<num.at(it)*(int)(pow(10,it)+0.5)<<" ";
		}}
	}
}
