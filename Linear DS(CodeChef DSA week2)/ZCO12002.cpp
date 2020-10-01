//https://www.codechef.com/LRNDSA02/problems/ZCO12002
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
typedef long long ll;

int main(){
	ll n,x,y;
	cin >> n >> x >> y;

	set < ll > v;
	set < ll > w;
	set < ll >::iterator itr;

	int contest[n][2];
	for(ll i=0; i<n; i++)
		cin >> contest[i][0] >> contest[i][1];

	for(ll i=0; i<x; i++){
		ll a;
		cin >> a;
		v.insert(a);
	}
	for(ll i=0; i<y; i++){
		ll b;
		cin >> b;
		w.insert(b);
	}

	ll min_before,min_after;
	ll curr_min;

	for(ll i=0; i<n; i++){
		if(v.find(contest[i][0])!=v.end())
			min_before = contest[i][0];
		else{
			if(*v.begin() > contest[i][0])
				continue;
			v.insert(contest[i][0]);
			itr = v.find(contest[i][0]);
			itr--;
			min_before = *itr;
			v.erase(contest[i][0]);
		}
		if(w.find(contest[i][1])!=w.end())
			min_after = contest[i][1];
		else{
			if(*w.rbegin() < contest[i][1])
				continue;
			w.insert(contest[i][1]);
			itr = w.find(contest[i][1]);
			itr++;
			min_after = *itr;
			w.erase(contest[i][1]);
		}
		if(i==0)
			curr_min = (min_after-min_before+1);
		else{
			if(curr_min > (min_after-min_before+1))
				curr_min = (min_after-min_before+1);
		}
		//cout << "#" << i << " : " << min_before << " " << min_after << " " << curr_min << '\n';
	}
	cout << curr_min;
}