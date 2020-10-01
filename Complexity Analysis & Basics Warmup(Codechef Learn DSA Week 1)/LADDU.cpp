//https://www.codechef.com/LRNDSA01/problems/LADDU
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    string s;
	    cin>>n>>s;
	    int laddus=0;
	    while(n--)
	    {
	        string str;
	        cin>>str;
	        if(str=="CONTEST_WON")
	        {
	            laddus+=300;
	            int rank;
	            cin>>rank;
	            if(rank<20)
	            laddus+=(20-rank);
	        }
	        else if(str=="TOP_CONTRIBUTOR")
	        laddus+=300;
	        else if(str=="BUG_FOUND")
	        {
	            int severe;
	            cin>>severe;
	            laddus+=severe;
	        }
	        else if(str=="CONTEST_HOSTED")
	        laddus+=50;
	    }
	    
	    if(s=="INDIAN")
	    cout<<laddus/200<<'\n';
	    else if(s=="NON_INDIAN")
	    cout<<laddus/400<<'\n';
	}
	return 0;
}
