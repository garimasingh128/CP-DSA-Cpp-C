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
int a[100005], b[100005], c[100005];


// dp[i][x] -- max point of happiness if he does activity x at day i
// complexity -- Time-O(N), Space-O(N)



void solve_itr(){
    int dp[n+5][3];
    memset(dp, -1, sizeof(dp));
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = b[n-1];
    dp[n-1][2] = c[n-1];
    for(int i = n-2; i >= 0; i--){
        dp[i][0] = a[i] + max(dp[i+1][1], dp[i+1][2]);
        dp[i][1] = b[i] + max(dp[i+1][0], dp[i+1][2]);
        dp[i][2] = c[i] + max(dp[i+1][0], dp[i+1][1]);
    }
    int ans = max(dp[0][0], max(dp[0][1], dp[0][2]));
    
    cout << ans << endl;
}

int dp[100005][3];

int get(int day, int task){
    if(day >= n) return 0;
    if(dp[day][task] == -1){
        if(task == 0){
            dp[day][task] = a[day] + max(get(day+1, 1), get(day+1, 2));
        }
        else if(task == 1){
            dp[day][task] = b[day] + max(get(day+1, 0), get(day+1, 2));
        }
        else{
            dp[day][task] = c[day] + max(get(day+1, 1), get(day+1, 0));
        }
    }
    return dp[day][task];
}

void solve_rec(){
    memset(dp, -1, sizeof(dp));
    int aa = get(0, 0);
    int bb = get(0, 1);
    int cc = get(0, 2);
    int ans = max(aa, max(bb, cc));
    cout << ans << endl;
}

int32_t main(){
    cin >> n;
    loop(n) cin >> a[i] >> b[i] >> c[i];

    // solve_itr();
    solve_rec();
}