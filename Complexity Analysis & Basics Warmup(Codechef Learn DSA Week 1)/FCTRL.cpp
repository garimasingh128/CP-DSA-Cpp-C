//https://www.codechef.com/LRNDSA01/problems/FCTRL
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	std::cin>>t;
	while(t--)
	{
	    int n,n_5=0;
	    std::cin>>n;
	    int x=5;
	    while(x<=n)
	    {
	        n_5+=(n/x);
	        x*=5;
	    }
	    std::cout<<n_5<<'\n';
	}
	return 0;
}
