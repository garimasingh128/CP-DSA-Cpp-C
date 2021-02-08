//https://www.codechef.com/LRNDSA02/problems/COMPILER
#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		string s;
		cin >> s;
		int count = 0;
		int i,prefix=0;
		for(i = 0 ; i < s.length() ; i++)
		{
			if(s[i]=='>')
				count--;
			else if(s[i]=='<')
				count++;
				
			if(count==0)
			    prefix=i+1;
			if(count==-1)
				break;
		}
		cout << prefix << '\n';
	}
}