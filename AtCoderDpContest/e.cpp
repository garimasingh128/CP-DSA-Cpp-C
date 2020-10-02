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
int v[105], w[105];

// dp[i] -- min weight required value i

int32_t main(){
    cin >> n >> W;
    loop(n) cin >> w[i] >> v[i];
    int max_val = 0;
    loop(n) max_val += v[i];
    vin dp(max_val+5, 1e12);

    dp[0] = 0;
    loop(n){
        for(int j = max_val; j >= v[i]; j--){
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    for(int i = max_val; i > 0; i--){
        if(dp[i] <= W) {
            cout << i << endl;
            break;
        }
    }
}
