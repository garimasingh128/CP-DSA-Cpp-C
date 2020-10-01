//https://www.codechef.com/LRNDSA02/problems/PSHOT
#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7
typedef long long ll;

int main()
{
	//A first
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		string goals;
		cin>>goals;
		int a_goals=0,b_goals=0,a_att=n,b_att=n;

		for(int i=0;i<2*n;i++)
		{
			if(i%2==0)
			{
				a_att--;
				if(goals[i]=='1')
				a_goals++;
			}

			else if(i%2!=0)
			{
				b_att--;
				if(goals[i]=='1')
				b_goals++;
			}

			if((a_goals>(b_goals+b_att))||(b_goals>(a_goals+a_att)))
			{
				cout << i+1 <<'\n';
				flag=1;
				break;
			}
		}
		if(!flag)
			cout<< 2*n <<'\n';
	}
}