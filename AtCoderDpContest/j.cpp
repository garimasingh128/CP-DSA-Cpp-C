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
int arr[4] = {0};

double dp[305][305][305];


double expect(int a, int b, int c, int tab){
    double s = a+b+c;
    if(s == 0) return 0;

    if(dp[a][b][c] == -1){
        dp[a][b][c] = (double)n/s;
        if(a > 0) dp[a][b][c] += ((double)a/s)*expect(a-1, b, c, tab+1);
        if(b > 0) dp[a][b][c] += ((double)b/s)*expect(a+1, b-1, c, tab+1);
        if(c > 0) dp[a][b][c] += ((double)c/s)*expect(a, b+1, c-1, tab+1);
    }
    return dp[a][b][c];
}


int32_t main(){
    cin >> n;
    int temp;
    for(int i = 0; i < 305; i++)
        for(int j = 0; j < 305; j++)
            for(int k = 0; k < 305; k++)
                dp[i][j][k] = -1;

    loop(n) {
        cin >> temp;
        arr[temp]++;
    }
    cout << setprecision(12);
    cout << expect(arr[1], arr[2], arr[3], 0) << endl;
}