//https://www.codechef.com/LRNDSA01/problems/CONFLIP
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	std::cin>>t;
	while(t--)
	{
	    int g;
	    std::cin>>g;
	    while(g--)
	    {
	        int i,n,q;
	        std::cin>>i>>n>>q;
	        if(n%2==0)
	        {
	            std::cout<<n/2<<'\n';
	        }
	        else
	        {
	            if(i==q)
	            {
	                std::cout<<n/2<<'\n';
	            }
	            else
	            {
	                std::cout<<(n/2)+1<<'\n';
	            }
	        }
	    }
	}
	return 0;
}
