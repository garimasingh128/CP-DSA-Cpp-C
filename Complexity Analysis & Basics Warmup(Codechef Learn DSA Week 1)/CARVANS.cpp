//https://www.codechef.com/LRNDSA01/problems/CARVANS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,a[10000];
	    std::cin>>n;//8 3 6
	    int max=n;
	    for(int i=0;i<n;i++)
	    std::cin>>a[i];
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[i]>a[j])
	            {
	                max--;
	                break;
	            }
	        }
	    }
	    std::cout<<max<<'\n';
	}
	return 0;
}
