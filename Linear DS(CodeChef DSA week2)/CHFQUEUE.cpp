//https://www.codechef.com/LRNDSA02/problems/CHFQUEUE
#include <bits/stdc++.h>

using namespace std;

stack < pair< int, int > > junior;

#define mod 1000000007
typedef long long ll;

int main(){
	int n,k;
	cin >> n >> k;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	ll b[n];
	for(int i=0; i<n; i++){
		b[i]=1;
	}


	for(int i=0; i<n; i++){
		if(junior.empty()||junior.top().first<=a[i]){
			junior.push({a[i],i});
		}
		else{
			while(!junior.empty()&&junior.top().first>a[i]){
				b[junior.top().second]=i-junior.top().second+1;
				junior.pop();
			}
			junior.push({a[i],i});
		}
	}
	ll fear=1;
	for(int i=0; i<n; i++)
		fear=(fear*(b[i]%mod))%mod;

	cout << fear ;
}