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

int nodes, edges;

vin adj_list[100005];
int dp[100005];

/*
    key idea: best part is the given graph DAG(directed acyclic graph) so longest path will be 
              max depth cocidering node i (1 <= i <= n)
              also max depth for any node will be alwyas same(due to DAG)
              so 
*/


int dfs(int node){
    if(dp[node] == -1){
        int ans = 0;
        for(auto i : adj_list[node]) ans = max(ans, dfs(i) + 1);
        dp[node] = ans;
    }
    return dp[node];
}

int32_t main(){
    cin >> nodes >> edges;
    int a, b;
    memset(dp, -1, sizeof(dp));
    loop(edges){
        cin >> a >> b;
        adj_list[a].pb(b);
    } 
    int ans = 0;
    for(int i = 1; i <= nodes; i++) ans = max(ans, dfs(i));
    cout << ans << endl;
}