//https://www.codechef.com/LRNDSA01/problems/ZCO14003
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n,budget[500000];
	std::cin>>n;
	for(long long int i=0;i<n;i++)
	std::cin>>budget[i];
	sort(budget,budget+n);
	
	for(long long int i=0;i<n;i++)
	budget[i]=budget[i]*(n-i);
	
	long long int max=budget[0];
	for(long long int i=1;i<n;i++)
	{
	    if(budget[i]>max)
	     max=budget[i];
	}
	
	std::cout<<max;
	
	return 0;
}
