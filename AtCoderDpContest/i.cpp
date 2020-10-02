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
double probs[3005];
double dp[3005][3005];

double get(int start, int rem, int tab){
    if(rem > start) return 0;
    if(rem == 0 and start == 0) return 1;
    if(dp[start][rem] == -1){
        if(rem == 0) dp[start][rem] = (1-probs[start])*get(start-1, rem, tab+1);
        else dp[start][rem] = probs[start]*get(start-1, rem-1, tab+1) + (1-probs[start])*get(start-1, rem, tab+1);
    }
    return dp[start][rem];
}

int32_t main(){

    loop(3005) for(int j = 0; j < 3005; j++) dp[i][j] = -1;

    dp[0][0] = 1;

    cout << setprecision(10);
    cin >> n;
    loop(n) cin >> probs[i+1];
    int s = ceil(n/(2.0));
    
    double ans = 0;
    Loop(s, n+1, i){
        double temp = get(n, i, 0);
        ans += temp;
    }
    cout << ans << endl;
}