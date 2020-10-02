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
#define w(t, flag) int tc = 1; if(flag)cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()

string str;
int base;
vin limits(10005);
int len;

int dp[10005][110][2];

int fun(int ind, int crr_sum, bool unlimited){

    if(dp[ind][crr_sum][unlimited] == -1){
        int limit = unlimited ? 10 : limits[ind];
        int ans = 0;
        if(ind == len-1){
            loop(limit)     
                if((crr_sum + i)%base == 0){
                    ans = ans + 1;
                    if(ans > mod) ans -= mod;
                }
            if(!unlimited and ((crr_sum+limit)%base == 0)){
                ans++;
                if(ans > mod) ans -= mod;
            }
        }
        else{
            loop(limit) ans = (ans + fun(ind+1, (crr_sum + i)%base, true))%mod;
            if(!unlimited) ans = (ans + fun(ind+1, (crr_sum+limit)%base, false))%mod;
        }
        dp[ind][crr_sum][unlimited] = ans; 
    }


    return dp[ind][crr_sum][unlimited];
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> str;
    cin >> base;
    len = str.size();
    loop(len) limits[i] = str[i]-'0';
    int ans = (fun(0, 0, false) - 1);
    if(ans > mod) ans -= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
    ans %= 
}