#include <bits/stdc++.h>

using namespace std;

int main(){ 
 	string s;
 	cin>>s;
 	
 	map<char, int> mp;
 	for(int i=0;i<(int)s.length();i++)
 	{
 		if(s[i]>='a' && s[i]<='z')
 		{
 		mp[s[i]]++;	
		 }
	}
	int c=0;
	for (it = MyMap1.begin(); it != MyMap1.end(); it++) 
	{ 
	if(j->second)
	c++;	
	}
	cout<<c;
	
    return 0;
}
