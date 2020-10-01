//https://www.codechef.com/LRNDSA01/problems/FLOW007
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	std::cin>>t;
	while(t--)
	{
	    int n;
	    std::cin>>n;
	    int rev=0;
	    while(n>0)
	    {
	        int ld=n%10;
	        rev=(rev*10)+ld;
	        n=n/10;
	    }
	    std::cout<<rev<<'\n';
	}
	return 0;
}
