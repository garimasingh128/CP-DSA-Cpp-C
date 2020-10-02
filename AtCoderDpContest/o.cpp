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

int off_bit[30];
int power_of_2[30];

int power(int a, int p, int md = 1000000007){
    int ans = 1;
    while(p){
        if(p&1) ans *= a, ans %= md;
        a *= a;
        ans %= md;
        p >>= 1; 
    }
    return ans;
}

int match[30][30] = {0};

int get_offbit(int bitno){
    int temp = 0;
    loop(22){
        temp += power_of_2[i];
    }
    temp -= power_of_2[bitno];
    return temp;
}

int dpt[25][(int)5e6];

int fun(int dp, int i, int tab){
    // loop(tab) cout << "   "; deb2(dp, tab);
    if(dpt[i][dp] == -1){

        int ans = 0;
        if(i == n-1){
            Loop(0, n, j){
                if((dp & power_of_2[j]) and match[i][j]) ans++;
                ans %= mod;
            }
        }
        else{            
            Loop(0, n, j){
                if((dp & power_of_2[j]) and match[i][j]){
                    int dp2 = dp;
                    dp2 = dp2 & off_bit[j];
                    ans += fun(dp2, i+1, tab+1);
                    ans %= mod;
                }
            }
        }
        dpt[i][dp] = ans;
    }
    return dpt[i][dp];
}

int32_t main1(){
    loop(10) deb(get_offbit(i));
}

int32_t main(){
    cin >> n;
    memset(dpt, -1, sizeof(dpt));
    loop(25) power_of_2[i] = power(2, i);
    loop(25) off_bit[i] = get_offbit(i);

    loop(n) Loop(0, n, j) cin >> match[i][j];
    int dp = power_of_2[n]-1;
    int ans = fun(dp, 0, 0);
    
    cout << ans << endl;
}   