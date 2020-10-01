// KICKSTART ROUND C 2019//
//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2/0000000000150aac
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const long long int  C = 5*(1e4)+1; 
set < pair<ll,ll> > rows[C+1];
set < pair<ll,ll> > cols[C+1];			
const ll INF=1e18;
ll r,c;


void COLS(ll x,ll y)
{ ll l,r;
	//cout<<"Segments in col "<<y<<"are:\n";
	//for(auto it:cols[y])
	//	{
	//	cout<<it.first<<" "<<it.second<<"\n";
	//}
	auto it=cols[y].upper_bound({x,INF});	
	if(it!=cols[y].begin())
	it--;		
	l=it->first;
	r=it->second;
	if(x>l && x<r)
	{
		cols[y].erase(it);
		cols[y].insert({l,x-1});
		cols[y].insert({x+1,r});		
	}
	
	else if(x==l)
	{
		
		cols[y].erase(it);
		if(l!=r)
		cols[y].insert({x+1,r});
		
	}
	
	else if(x==r)
	{
		
		cols[y].erase(it);
		if(l!=r)
		cols[y].insert({l,x-1});
	}
	
}

void ROWS(ll x,ll y)
{
	ll l,r;
	//cout<<"Segments in row "<<x<<" are:\n";
	//for(auto it:rows[x])
	//{
	//	cout<<it.first<<" "<<it.second<<"\n";
	//}
	auto it=rows[x].upper_bound({y,INF});
	if(it!=rows[x].begin())
	it--;
	
	l=it->first;
	r=it->second;
	if(y>l && y<r)
	{
		rows[x].erase(it);
		rows[x].insert({l,y-1});
		rows[x].insert({y+1,r});		
	}
	
	else if(y==l)
	{
		
		rows[x].erase(it);
		if(l!=r)
		rows[x].insert({y+1,r});
	}
	
	else if(y==r)
	{
		
		rows[x].erase(it);
		if(l!=r)
	 rows[x].insert({l,y-1});
	}
	
}

pair <ll,ll> move(ll x,ll y,char c)
{
		// remove y from rows[x]
		ROWS(x,y);		
		//remove x from cols[y]
		COLS(x,y);
		// find current position after movement
		set < pair<ll,ll> > ::iterator it;
		switch(c)
		{
			case 'W':it=rows[x].lower_bound({y,-INF});
								if(it!=rows[x].begin())
								it--;
								y=it->second;			
								break;							
			case 'E':it=rows[x].upper_bound({y,INF});
								y=it->first;		
								break;
			case 'N':it=cols[y].lower_bound({x,-INF});
								if(it!=cols[y].begin())	
								it--;
								x=it->second;		
								break;
			case 'S':it=cols[y].upper_bound({x,INF});
								x=it->first;	
		}
		
		return make_pair(x,y);
}

int main(void)
{
	
	ll t,n,sr,sc,i,j;
	cin>>t;
	for(j=1;j<=t;j++)
	{
			cin>>n>>r>>c>>sr>>sc;
			
			for(i=1;i<=r;i++)
			rows[i].insert({1,c});
		
			for(i=1;i<=c;i++)
			cols[i].insert({1,r});
		
			for(i=1;i<=n;i++)
			{
				char(ch);
				cin>>ch;				
				pair <ll,ll> p=move(sr,sc,ch);
				sr=p.first;
				sc=p.second;
				//cout<<"New position is:\n";
				//cout<<ch<<sr<<" "<<sc<<"\n";
			}
		
			cout<<"Case #"<<j<<": "<<sr<<" "<<sc<<"\n";
			
			
		for(i=1;i<=r;i++)
		rows[i].clear();
		
		for(i=1;i<=c;i++)
		cols[i].clear();
		
	}
	
	
	
}
