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


int dp[3003][3003];
int INF = 5000;
int slen;
int tlen;
string s, t;

string ans;

/*
    Key idea: here we are using dp[i][j] which provides length of LCS possible for index 0 to i 
    and 0 to j for s and t respectively

    stating from back, using dp array that there are 2 conditions
    1. s[i] == t[j] => in this condition we simpally add s[i] to answer
    2. s[i] != t[j] => here we have two options
                            1. ignore s[i] i.e. concider i-1, j 
                            2. ignore t[j] i.e. concider i, j-1
                to decide among above two cases we are using dp array

    so dp[i][j] -> length of max possible LCS from 0 to i of s and 0 to j of t
    complexity => time-O(N), space-O(N^2)
*/


int fun(int a, int b){

    if(a < 0 or b < 0) return 0;
    if(dp[a][b] == -1){
        if(s[a] == t[b]){
            dp[a][b] = fun(a-1, b-1) + 1;
        }
        else dp[a][b] = max(fun(a, b-1), fun(a-1, b));
    }
    return dp[a][b];
}

void fun1(int a, int b){
    if(a < 0 or b < 0) return;
    if(s[a] == t[b]) {
        ans += s[a];
        fun1(a-1, b-1);
    }
    else if(fun(a-1, b) > fun(a, b-1)) fun1(a-1, b);
    else fun1(a, b-1);
    
}

int32_t main(){
    
    memset(dp, -1, sizeof(dp));
    cin >> s;
    cin >> t;
    tlen = t.length();
    slen = s.length();
    fun1(slen-1, tlen-1); 
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}