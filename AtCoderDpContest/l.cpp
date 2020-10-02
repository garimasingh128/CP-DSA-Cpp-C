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
int arr[3005];

pii dp_fist[3005][3005];
pii dp_second[3005][3005];

int vis_first[3005][3005];
int vis_second[3005][3005];

pii second(int, int);

pii first(int i, int j){
    
    if(i == j) return {arr[i] , 0};
    if(vis_first[i][j] == -1){
        vis_first[i][j] = 1;
        pii a = second(i+1, j);
        a.first += arr[i];
        pii b = second(i, j-1);
        b.first += arr[j];

        if(a.first - a.second > b.first - b.second) dp_fist[i][j] = a;
        else dp_fist[i][j] = b;
    }
    return dp_fist[i][j];
}

pii second(int i, int j){

    if(i == j) return {0, arr[i]};
    if(vis_second[i][j] == -1){
        vis_second[i][j] = 1;
        pii a = first(i+1, j);
        a.second += arr[i];
        pii b = first(i, j-1);
        b.second += arr[j];

        if(a.first - a.second < b.first - b.second) dp_second[i][j] = a;
        else dp_second[i][j] = b;
    }
    return dp_second[i][j];
}


int32_t main(){
    memset(vis_first, -1, sizeof(vis_first));
    memset(vis_second, -1, sizeof(vis_second));
    cin >> n;
    loop(n) cin >> arr[i];
    pii ans = first(0, n-1);
    cout << ans.first - ans.second << endl;
}