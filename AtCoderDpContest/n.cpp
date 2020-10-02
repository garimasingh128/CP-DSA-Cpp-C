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
int arr[405];
int length[405][405];

int dp[405][405];

int get(int i, int j, int tab){
    if(i == j) return 0;
    if(dp[i][j] == -1){
        int ans = INT64_MAX;
        for(int k = i; k < j; k++){
            // loop(tab) printf("    "); cout << i << k << " " << k+1 << j << endl;
            int temp = 0;
            temp += (int)length[i][k];
            temp += (int)length[k+1][j];
            temp += (int)get(i, k, tab+1);
            temp += (int)get(k+1, j, tab+1);
            ans = min(ans, temp);   
        }
        dp[i][j] = ans;
    }
    return dp[i][j];
}

// do this by bottam up also

int32_t main(){
    cin >> n;
    loop(n) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    loop(n) 
        length[i][i] = arr[i];
    
    loop(n)
        for(int j = i+1; j < n; j++) 
            length[i][j] = length[i][j-1] + arr[j];

    int ans = get(0, n-1, 0);
    cout << ans << endl;
}