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

int dp[1002][1002];
int h, w;

int find(int i, int j){
    if(i > h or j > w) return 0;
    if(dp[i][j] == -1){
        dp[i][j] = (find(i+1, j) + find(i, j+1))%mod; 
    }
    return dp[i][j];
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> h >> w;
    char temp;
    dp[h][w] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> temp;
            if(temp == '#') dp[i][j] = 0;
        }
    }

    cout << find(1, 1);
}