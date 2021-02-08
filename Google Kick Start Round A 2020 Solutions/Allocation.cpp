#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, b;
int a[N];
int ans = 0;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0; 
	while(t--)
	{
		tc++;
		cin >> n >> b;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] <= b)
			{
				ans++;
				b -= a[i];
			}
		}
		cout << "Case #" << tc << ": " << ans << endl;
 	}	
	return 0;
}