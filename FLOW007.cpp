#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	long long int r[t];
	for(int i=1;i<=t;i++)
	{
	    long long int n,q,rev,rem;
	    cin>>n;
	    while(n!=0)
	    {
	        q=n%10;
	        rev=rev*10+q;
	        n=n/10;
	    }
	    r[i]=rev;
	}
	for(int i=1;i<=t;i++)
	{
	    cout<<r[i]<<endl;
	}
	return 0;
}

