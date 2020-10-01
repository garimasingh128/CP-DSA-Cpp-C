//https://www.codechef.com/LRNDSA02/problems/NOTALLFL
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
typedef long long ll;

int main(){
	int t;
	cin >> t;
	while( t-- ){
		int n,k;
		cin >> n >> k;
		int a[n];
		map < int , int > last_occur; //to update last occur
		map < int , int >::iterator itr;
		for(int i=0; i<n; i++){
			cin >> a[i];
			last_occur[a[i]]=-1;
		}
		if(last_occur.size() < k){
			cout << n << '\n';
			continue;
		}
		set < pair<int , int> > last_rem_add; //to find min of last occur
		for(itr=last_occur.begin(); itr!=last_occur.end(); itr++)
			last_rem_add.insert({itr->second,itr->first});

		int max = 0;
		for(int i=0; i<n; i++){
			last_rem_add.erase({last_occur[a[i]],a[i]});
			last_occur[a[i]]=i;
			last_rem_add.insert({last_occur[a[i]],a[i]});
			int curr_max = i - (last_rem_add.begin()->first);
			if(curr_max > max)
				max = curr_max;
		}
		cout << max << '\n';
	}
}