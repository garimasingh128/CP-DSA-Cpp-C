#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;
const int K = 35;

int n, k, p;
int a[N][K];
int cache[N][N * K];

int dp(int idx, int taken)
{
	if(taken == 0)
		return 0;
	if(taken < 0)
		return -2e9;
	if(idx > n)
		return 0;
	int &ans = cache[idx][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int val = 0;
	for(int i = 0; i <= k; i++)
	{
		val += a[idx][i];
		ans = max(ans, val + dp(idx + 1, taken - i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0; 
	while(t--)
	{
		memset(cache, -1, sizeof(cache));
		tc++;
		cin >> n >> k >> p;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= k; j++)
				cin >> a[i][j];
		int ans = dp(1, p);
		cout << "Case #" << tc << ": " << ans << endl;
 	}	
	return 0;
}