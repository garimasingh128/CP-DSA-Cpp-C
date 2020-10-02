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
vec<vin> adj(100005);
int dp[100005][3];

// 0 black
// 1 white

int get(int a, int c, int tab){

    if(dp[a][c] == -1){
        int final_ans = 0;
        if(c == 0){
            if(adj[a].size() == 0) final_ans = 1;
            else{
                int ans = 1;
                for(int i : adj[a]){
                    vin::iterator temp = find(adj[i].begin(), adj[i].end(), a);
                    if(temp != adj[i].end()) adj[i].erase(find(adj[i].begin(), adj[i].end(), a));
                    ans = (ans * get(i, 1, tab+1)) % mod;
                }
                final_ans = ans;
            } 
        }
        else{
            if(adj[a].size() == 0) final_ans = 1;
            else{
                int ans1 = 1;
                for(int i : adj[a]){
                    vin::iterator temp = find(adj[i].begin(), adj[i].end(), a);
                    if(temp != adj[i].end()) adj[i].erase(find(adj[i].begin(), adj[i].end(), a));
                    ans1 = (ans1 * (get(i, 1, tab+1) + get(i, 0, tab+1))) % mod;
                }
                final_ans = (ans1)%mod;
            }
        }
        dp[a][c] = final_ans;
    }
    return dp[a][c];
}

int32_t main(){
    cin >> n;
    int a, b;
    memset(dp, -1, sizeof(dp));
    loop(n-1){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = (get(1, 0, 0) + get(1, 1, 0))%mod;
    cout << ans;
}