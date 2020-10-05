#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	vector<int> k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int kd;
		cin>>kd;
		k.push_back(kd);
	}
	sort(k.begin(),k.end());
	int d=k.back()-k.front();
	int r=d-n+1;
	cout<<r;
}
