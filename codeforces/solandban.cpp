#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,n,w,sum=0;
	int amt;
	cin>>k>>n>>w;
	for(int i=1;i<=w;i++){
		sum=sum+i*k;
	}
	if(sum<n){
		cout<<0<<endl;
	}
	else{
	amt=sum-n;
	cout<<amt<<endl;}
}
