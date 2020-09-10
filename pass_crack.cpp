#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define mii map<int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define pt(a) cout << a << endl;
#define ptt(a, b) cout << a << " " << b << endl;
#define ptf(a) cout << a << " ";
#define rd(a) cin >> a;
#define rdd(a, b) cin >> a >> b;
#define loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define lop(n) for(int i = 0; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define lopk(n) for(int k = 0; k < n; k++)
#define vin vector<int>
#define w(flag) int tc = 1; if(flag) cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define elif else if
#define nline cout << endl;

int ar[1000006] = {0};
int n = 0;
int tp(0), tp1(0), tp2(0), tp3(0), tp4(0);
string str;
int len;
void pre_processing(){}

vec<string> passes;
vec<int> sizes(100);
string attempt;

int visited[5000];
vec<string> dp(5000);
string wrong = "WRONG PASSWORD";


string find(string s, int index, int tabs = 0){

    if(visited[index])
    {
        return dp[index];
    }
    int l = s.size();
    for(int i = 0; i < n; i++)
    {
        if(l >= sizes[i])
        {
            bool matched = true;
            for(int j = 0; j < sizes[i]; j++)
            {
                if(s[j] != passes[i][j])
                {
                    matched = false;
                    break;
                }
            }
            if(matched)
            {
                string s1 = s.substr(sizes[i]);
                if(s1 == "")
                {
                    s1 = passes[i];
                    dp[index] = s1;
                    visited[index] = 1;
                    return s1;
                }
                s1 = find(s1, index + sizes[i], tabs+1);
                if(s1 != wrong)
                {
                    s1 = passes[i] + " " + s1;
                    dp[index] = s1;
                    visited[index] = 1;
                    return s1;
                }
            }
        }
    }
    visited[index] = 1;
    dp[index] = wrong;
    return wrong;
}

void solve()
{
    passes.clear();
    rd(n)
    lop(n)
    {
        rd(str)
        passes.pb(str);
        sizes[i] = str.length();
    }
    rd(attempt);
    len = attempt.size();
    lop(len)
        visited[i] = 0;
    str = find(attempt, 0);
    cout << str << endl;
}

int32_t main()
{
    // fastio;
    pre_processing();
    w(true)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
