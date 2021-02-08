/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

int ask(int x, int y)
{
    cout << x << " " << y << endl;
    string ans;
    cin >> ans;
    if (ans == "WRONG")
        exit(0);
    if (ans == "CENTER")
        return 0;
    if (ans == "HIT")
        return 1;
    return -1;
}

int A, B;

ll func(ll x, ll y, ll dx, ll dy)
{
    ll l = 0;
    ll r = 2e9 + 1;
    while (r - l > 1)
    {
        ll h = (l + r) / 2LL;
        ll nx = x + h * dx;
        ll ny = y + h * dy;
        if (abs(nx) > (int)1e9 || abs(ny) > (int)1e9)
        {
            r = h;
            continue;
        }
        int t = ask(nx, ny);
        if (t == 0)
            return -1;
        if (t == 1)
            l = h;
        else
            r = h;
    }
    return l;
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void solve()
{
    int JMP = 1e9;
    JMP /= 4;
    int x, y;
    for (int i = -JMP * 3; i <= 3 * JMP; i += JMP)
        for (int j = -JMP * 3; j <= 3 * JMP; j += JMP)
        {
            int t = ask(i, j);
            if (t == 0)
                return;
            if (t == 1)
            {
                x = i;
                y = j;
                break;
            }
        }
    vector<ll> f(4);
    for (int d = 0; d < 4; d++)
    {
        f[d] = func(x, y, dx[d], dy[d]);
        if (f[d] == -1)
            return;
    }
    ll xn = ((f[2] - f[3]) / 2) + x;
    ll yn = ((f[0] - f[1]) / 2) + y;
    assert(ask(xn, yn) == 0);
}

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T >> A >> B;
    for (int i = 0; i < T; i++)
        solve();
    return 0;
}