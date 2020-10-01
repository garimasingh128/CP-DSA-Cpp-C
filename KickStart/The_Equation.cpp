//ROUND G KICK START 2019//
// Problem link https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fe36

#include<bits/stdc++.h>
#include<cmath>
using namespace std;
using ll = long long int;

ll Solve(vector <ll> &A,ll m)
{
	ll n=A.size();
	vector <ll> ones(51);
	vector <ll> F(51);
		
	  for(ll i=0;i<n;i++)		
		for(ll j=50;j>=0;j--)
		{
				if(((1ll)<<j)&A[i])
				ones[j]++;
			
		}
		
		F[0]=min(ones[0],n-ones[0]);
//		cout<<"Values of F are:  ";
		for(ll j=1;j<51;j++)
		{
				F[j]=F[j-1] + min(ones[j],n-ones[j])*pow(2,j);
//				cout<<F[j]<<" ";
		}
//		cout<<"\n";
		ll k=0;
			int flag=0;
		for(ll i=50;i>0;i--)
		{
			
			ll zeroes=n-ones[i];
		
			
			if(zeroes*pow(2,i) + F[i-1]<=m)
			{	
				k+=pow(2,i);
				m-=(zeroes*pow(2,i));
			}
			
			else if(ones[i]*pow(2,i) + F[i-1] <=m)
			{
				m-=(ones[i]*pow(2,i));
			}		
			else if(m<F[i])
			{flag=1;break;
			}
			
//			else {
//				flag=1;break;
//			}
			
//			cout<<i<<"-->"<<k<<"  "<<m<<"\n";
		}		
		
		if(flag==0)
		{
			ll zeroes=n-ones[0];
			if(zeroes <=m)
			{	
				k+=1;
				m-=zeroes;
			}
			
			else if(ones[0]<=m)
			{
				m-=ones[0];
			}		
			else if(m<F[0])
			{flag=1;
			}
			
		}
		
		if(!flag)return k;
		else return -1;
		
}

//ll Generator(vector <ll> &A, ll m)
//{
//	
//	for(ll k=1e7;k>=0;k--)
//	{ll x=0;
//		for(ll i=0;i<A.size();i++)
//		{
//		
//			x+=(k^A[i]);
//		
//		}
//		
//		if(x<=m)
//		return k;
//		
//	}
//	return -1;
//}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t,n,m,temp,j;
	cin>>t;
	ll M=1e7+1;
	for(j=1;j<=t;j++)
	{
		cin>>n>>m;
//		m=(rand()+1)%M;
		vector <ll> A;
		for(ll i=0;i<n;i++)
		{
			cin>>temp;
//				temp=(rand()+1)%M;
			A.push_back(temp);
		}
		
		
		ll ans=Solve(A,m);
//		ll brute=Generator(A,m);
//		if(ans!=brute)
//		{
//				for(ll i=0;i<n;i++)
//				cout<<A[i]<<" ";
//			
//		}
		
		cout<<"Case #"<<j<<": "<<ans<<"\n";
//		cout<<" "<<brute<<"\n";
		
	}
	
	
}
