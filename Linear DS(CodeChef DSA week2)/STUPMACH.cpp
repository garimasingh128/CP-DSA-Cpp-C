//https://www.codechef.com/LRNDSA02/problems/STUPMACH
#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		vector <int> cap;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			cap.push_back(x);
		}
		ll tokens=0;
		int min=cap[0];
		for(int i=0;i<n;i++)
		{
			if(cap[i]<min)
				min=cap[i];

			tokens+=min;
		}

		cout<< tokens << '\n';
	}
}