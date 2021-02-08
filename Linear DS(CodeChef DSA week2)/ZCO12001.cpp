//https://www.codechef.com/LRNDSA02/problems/ZCO12001
#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for( int i=0; i<n; i++){
		cin >> a[i];
	}
	int depth=0,pos1=0,ele=0,pos2=0,ele_curr=0;
	stack < int > brakets;
	for(int i=0; i<n; i++){
		if(a[i]==1)
			brakets.push(a[i]);
		else
			brakets.pop();

		if(brakets.size()>depth){
			depth=brakets.size();
			pos1=i+1;
		}

		if(brakets.size()!=0){
			ele_curr++;
		}
		else{
			if(ele_curr+1>ele){
				ele=ele_curr+1;
				pos2=i-ele+1;
				ele_curr=0;
			}
			else
			    ele_curr=0;
		}
	}
	cout << depth <<" " << pos1 << " " << ele << " " << pos2+1;
}