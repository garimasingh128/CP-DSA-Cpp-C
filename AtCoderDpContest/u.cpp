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
int cost[20][20];

vin pre;
vin dp;

const int INF = 1e18+5;

void fun(int index, vin& rem, int score, int mask, int group){
    if(index == (int)rem.size()){
        dp[mask] = max(dp[mask], score + pre[group]);
        return;
    }
    else{
        fun(index+1, rem, score, mask, group);
        fun(index+1, rem, score, mask ^ (1 << rem[index]), group ^ (1 << rem[index]));
    }
}

int32_t main(){
    fastio;
    w(t, false){
        
        cin >> n;
        loop(n) 
            Loop(0, n, j) 
                cin >> cost[i][j];

        
        // pre processing
        pre.resize((1 << n), 0);
        for(int mask = 0; mask < (1<<n); ++mask){
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)){
                    for(int j = i+1; j < n; ++j){
                        if(mask & (1 << j)){
                            pre[mask] += cost[i][j]; 
                        }
                    }
                }
            }
        }

        dp.resize((1 << n), -INF);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask){
            vin rem;
            for(int j = 0; j < n; j++) 
                if(!(mask&(1 << j))) 
                    rem.pb(j);

            fun(0, rem, dp[mask], mask, 0);           
        }
        cout << dp[(1<<n)-1] << endl;
    }
}