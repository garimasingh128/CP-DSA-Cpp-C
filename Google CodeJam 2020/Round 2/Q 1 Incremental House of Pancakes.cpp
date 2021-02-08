/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int x, k;
int l, r;

bool check(int x)
{
    return x * (x + 1) / 2 <= k;
}

int binsearch(int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

bool check2(int k)
{
    int L = x * k + k * k;
    int R = L + k;
    return (L <= l && R <= r);
}

int binsearch2(int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (check2(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int get(int &l, int &r)
{
    int diff = max(l, r) - min(l, r);
    k = diff;
    x = binsearch(0, 2e9);
    if (l > r)
        l -= x * (x + 1) / 2;
    else
        r -= x * (x + 1) / 2;
    int ans = x;
    if (l < r)
    {
        if (r >= x + 1)
        {
            r -= x + 1;
            ans++;
            x++;
        }
        else
            return ans;
    }
    int y = binsearch2(0, 2e9);
    ans += 2 * y;
    int L = x * y + y * y;
    int R = L + y;
    l -= L;
    r -= R;
    x += 2 * y;
    if (l >= x + 1)
    {
        l -= (x + 1);
        ans++;
    }
    return ans;
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        cin >> l >> r;
        int ans = get(l, r);
        tc++;
        cout << "Case #" << tc << ": ";
        cout << ans << " " << l << " " << r << endl;
    }
    return 0;
}