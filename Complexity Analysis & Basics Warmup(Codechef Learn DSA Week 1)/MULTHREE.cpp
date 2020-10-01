//https://www.codechef.com/LRNDSA01/problems/MULTHREE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll t;
	std::cin>>t;
	while(t--)
	{
	    ll k,f,s;
	    std::cin>>k>>f>>s;
	    ll sum=(f+s)+((f+s)%10);
	    int th=(f+s)%10;
	    int l1=(2*th)%10;
	    int l2=(2*l1)%10;
	    int l3=(2*l2)%10;
	    int l4=(2*l3)%10;
	    
	    ll r=(k-3)%4;ll h=(k-3)/4;
	    if(r==1)
	    sum+=l1;
	    else if(r==2)
	    sum+=(l1+l2);
	    else if(r==3)
	    sum+=(l1+l2+l3);
	    
	    sum=sum+(h*(l1+l2+l3+l4));
	    
	    if(sum%3==0)
	    std::cout<<"YES\n";
	    else
	    std::cout<<"NO\n";
	    
	}
	return 0;
}
