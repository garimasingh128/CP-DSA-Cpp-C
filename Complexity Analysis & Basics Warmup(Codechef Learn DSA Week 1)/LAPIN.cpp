//https://www.codechef.com/LRNDSA01/problems/LAPIN
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	std::cin>>t;
	while(t--)
	{
	    string s;
	    std::cin>>s;
	    
	    int left[26];int right[26];
	    for(int i=0;i<26;i++)
	    {
	        left[i]=0;
	        right[i]=0;
	    }
	    
	    for(int i=0;i<s.length()/2;i++)
	    {
	        char curr=s[i];
	        left[curr-'a']++;
	    }
	    
	    for(int i=((s.length()+1)/2);i<s.length();i++)
	    {
	        char curr=s[i];
	        right[curr-'a']++;
	    }
	    int flag=1;
	    for(int i=0;i<26;i++)
	    {
	        if(left[i]!=right[i])
	    {flag=0;
	    break;}
	        
	    }
	    if(!flag)
	    std::cout<<"NO\n";
	    else
	    std::cout<<"YES\n";
	}
	return 0;
}
