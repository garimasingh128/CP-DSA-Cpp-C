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


int n, k;
int arr[105];

int dp_first[100005];
int dp_second[100005];


bool second(int);

bool first(int a){
    if(a == 0) return false;
    if(dp_first[a] == -1){
        bool flag = false;
        bool ans = false;
        loop(n){
            if(arr[i] <= a){
                flag = true;
                ans |= second(a - arr[i]);
            }
        }
        dp_first[a] = ans & flag;
    }
    return dp_first[a];
}

bool second(int a){
    if(a == 0) return true;
    if(dp_second[a] == -1){
        bool flag = true;
        bool ans = true;
        loop(n){
            if(arr[i] <= a){
                flag = false;
                ans &= first(a - arr[i]);
            }
        }
        dp_second[a] = ans | flag;
    }
    return dp_second[a];
}


int32_t main(){
    memset(dp_first, -1, sizeof(dp_first));
    memset(dp_second, -1, sizeof(dp_second));
    cin >> n >> k;
    loop(n) cin >> arr[i];
    if(first(k)) cout << "First\n";
    else cout << "Second\n";
}