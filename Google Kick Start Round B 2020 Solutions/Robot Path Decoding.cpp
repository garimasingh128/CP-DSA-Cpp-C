#include <bits/stdc++.h>
#define int long long int 
using namespace std;

// Author: Ashish

const int mod=1e9;

string str;

int evaluate_x()
{
	map<char,int> mp;
	mp['E']=1;
	mp['W']=-1;
	stack<pair<int,int>> st;
	st.push({1,0});
	for(int i=0;str[i];i++)
	{
		if(str[i]=='S' || str[i]=='N') continue;
		if(str[i]=='E' || str[i]=='W')
		{
			auto curr=st.top();
			st.pop();
			curr.second+=mp[str[i]]+mod;
			curr.second%=mod;
			st.push({curr.first,curr.second%mod});
		} 
		if(str[i]=='(')
		{
			int val=str[i-1]-'0';
			st.push({val,0});
		}
		if(str[i]==')')
		{
			auto curr=st.top();
			st.pop();
			auto prev=st.top();
			st.pop();
			prev.second+=(curr.first*curr.second%mod + mod)%mod;
			st.push({prev.first,prev.second%mod});
		}
	}
	return st.top().second;
}


int evaluate_y()
{
	map<char,int> mp;
	mp['S']=1;
	mp['N']=-1;
	stack<pair<int,int>> st;
	st.push({1,0});
	for(int i=0;str[i];i++)
	{
		if(str[i]=='E' || str[i]=='W') continue;
		if(str[i]=='S' || str[i]=='N')
		{
			auto curr=st.top();
			st.pop();
			curr.second+=mp[str[i]]+mod;
			curr.second%=mod;
			st.push({curr.first,curr.second});
		} 
		if(str[i]=='(')
		{
			int val=str[i-1]-'0';
			st.push({val,0});
		}
		if(str[i]==')')
		{
			auto curr=st.top();
			st.pop();
			auto prev=st.top();
			st.pop();
			prev.second+=(curr.first*curr.second%mod + mod)%mod;
			st.push({prev.first,prev.second%mod});
		}
	}
	return st.top().second;
}


int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  for(int _=1;_<=t;_++)
  {
  	cout<<"Case #"<<_<<": ";
  	cin>>str;
  	int x=evaluate_x(),y=evaluate_y();
  	cout<<x+1<<' '<<y+1<<'\n';
  }	
  

 	return 0;
}