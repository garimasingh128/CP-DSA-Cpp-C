#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define mii map<int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define Loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define loop(n) for(int i = 0; i < n; i++)
#define vin vector<int>
#define w(t) int tc; cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()

int n, W;
int w[105], v[105];

int dp[101][100005];

// dp[i][w] -- max profit for item i if total weight remaining is w
// complexity -- Time-O(item*weight), Space-O(item*weight)


int get(int it, int wt){
    if(wt < 0) return INT_MIN;
    if(it == n) return 0;
    if(dp[it][wt] == -1){
        dp[it][wt] = max(get(it+1, wt), get(it+1, wt-w[it]) + v[it]);
    }
    return dp[it][wt];
}

int32_t main(){
    cin >> n >> W;
    loop(n) cin >> w[i] >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << get(0, W);
}