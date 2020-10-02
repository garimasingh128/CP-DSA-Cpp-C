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
#define w(t, flag) int tc = 1; if(flag) cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()

int n;
string str;
int dp[3005][3005];


int32_t main(){
    fastio;
    w(t, false){
        cin >> n;
        cin >> str;
        dp[1][1] = 1;
        for(int pos = 2; pos <= n; ++pos){
            int sums[3005];
            for(int i = 1; i < pos; ++i)
                sums[i] = (sums[i-1] + dp[pos-1][i])%mod;
            
            for(int b = 1; b <= pos; ++b){
                int L, R;
                if(str[pos-2] == '<')
                    L = 1, R = b-1;
                else 
                    L = b, R = pos-1;

                if(L <= R)
                    dp[pos][b] = (dp[pos][b] + (sums[R] - sums[L-1] + mod))%mod;

            }
        }
        int ans = 0;
        for(int b = 1; b <= n; ++b)
            ans = (ans + dp[n][b])%mod;

        cout << ans << endl;
    }
}