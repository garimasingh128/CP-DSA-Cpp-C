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


int N, k; // N == 100, k == 1e5
int dp[105][100005] = {0};


int32_t main(){
    cin >> N >> k;
    int arr[105];
    Loop(1, N+1, i) cin >> arr[i];
    loop(103) dp[0][i] = 0;
    dp[0][0] = 1;
    Loop(1, N+1, i){
        int sums[100005] = {0};
        sums[0] = dp[i-1][0]%mod;
        dp[i][0] = sums[0];
        Loop(1, k+1, j){
            sums[j] = (sums[j-1] + dp[i-1][j])%mod;
            dp[i][j] = sums[j];

            int ur = j - arr[i] - 1;
            if(ur >= 0)    dp[i][j] = (dp[i][j] - sums[ur] + mod)%mod;
        } 
    }
    cout << dp[N][k] << endl;
}
