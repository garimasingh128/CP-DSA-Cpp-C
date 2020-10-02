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
vec<vin> table;

class segment_tree{
    int base = 1;
    int *tree;
    int *low;
    int *high;
    int def;

    // uncomment required line
    int fun(int a, int b){
        return max(a, b);
        // return min(a, b);
        // return a+b;
    }

    public: 
    

    segment_tree(vin heights){

        // set default return value

        def = 0; // for max
        // def = INT64_MAX; // for min
        // def = 0; // for sum


        int size = heights.size();
        while(size > base) base <<= 1;
        tree = new int[2*base];
        loop(size) tree[base+i] = heights[i];
        for(int i = base-1; i > 0; i--) tree[i] = fun(tree[2*i], tree[2*i+1]);

        low = new int[2*base];
        high = new int[2*base];

        loop(base) high[base+i] = low[base+i] = i;

        for(int i = base-1; i > 0; i--){
            low[i] = low[2*i];
            high[i] = high[2*i+1];
        }
    }

    void update(int index, int value){
        tree[base + index] = value;
        int i = (base+index)/2;
        while(i > 0) tree[i] = fun(tree[2*i], tree[2*i+1]), i >>= 1;
    }

    int query(int a, int b, int i = 1){
        int ans;
        if(a <= low[i] and b >= high[i]) ans = tree[i];
        else if(a > high[i] or b < low[i]) ans = def;
        else ans = fun(query(a, b, 2*i+1), query(a, b, 2*i));
        return ans;
    }
};

bool fun(vin a, vin b){
    return a[1] > b[1];
}

int32_t main(){
    
    cin >> n;
    table = vec<vin>(n, vin(3));// i height, buties
    loop(n){
        table[i][0] = i;
        cin >> table[i][1];
    }
    loop(n) cin >> table[i][2];

    vin ans(n, 0);
    segment_tree st(ans);

    sort(all(table), fun);    
    
    loop(n){
        int temp = st.query(table[i][0], n-1);
        st.update(table[i][0], temp+table[i][2]);
    }
    cout << st.query(0, n-1) << endl;
}