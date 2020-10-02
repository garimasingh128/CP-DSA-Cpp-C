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

const int MAXN = 50;

template<typename T>
T power(T a, int p, int md = 1000000007){
    T ans(1);
    while(p){
        if(p&1) ans = ans*a;
        a = a*a;
        p >>= 1; 
    }
    return ans;
}

struct matrix{
    int mat[MAXN][MAXN] = {0};
    matrix(int val = 0){
        loop(MAXN) 
            Loop(0, MAXN, j) 
                if(i == j) mat[i][j] = val; 
                else 0;
    }

    matrix operator*(matrix b){
        matrix ans;
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                for(int k = 0; k < MAXN; k++){
                    ans.mat[i][j] = ans.mat[i][j] + ((mat[i][k]%mod)*(b.mat[k][j]%mod))%mod; 
                    ans.mat[i][j] %= mod;
                }

        return ans;
    }

    
};


int32_t main(){
    int n;
    int k;
    cin >> n >> k;
    matrix a;
    loop(n) Loop(0, n, j) cin >> a.mat[i][j];
    matrix c = power<matrix>(a, k);

    int ans = 0;
    loop(n)
        Loop(0, n, j) 
            ans = (ans + c.mat[i][j])%mod;
    
    cout << ans << endl;

}