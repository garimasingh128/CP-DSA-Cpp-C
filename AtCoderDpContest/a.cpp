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

int n;
int heights[100005];
int dp[100005];


// dp[i] -- min cost to reach from i to n
// complexity -- Time-O(N), Space-O(N)

void solve_itr(){
    cin >> n;
    loop(n) cin >> heights[i+1];
    dp[n] = 0;
    dp[n-1] = abs(heights[n] - heights[n-1]);
    for(int i = n-2; i > 0; i--){
        dp[i] = min(
            dp[i+1] + abs(heights[i] - heights[i+1]), 
            dp[i+2] + abs(heights[i] - heights[i+2])
        );
    }

    
    cout << dp[1] << endl;
}

int go(int step){
    if(step > n) return INT_MAX;
    if(step == n) return 0;
    if(dp[step] == -1){
        dp[step] = min(
            abs(heights[step] - heights[step+1]) + go(step+1),
            abs(heights[step] - heights[step+2]) + go(step+2)
        );
    }
    return dp[step];
}

void solve_rec(){
    cin >> n;
    loop(n) cin >> heights[i+1];
    memset(dp, -1, sizeof(dp));
    cout << go(1) << endl;
}

int32_t main(){
    // solove_itr();
    solve_rec();
}