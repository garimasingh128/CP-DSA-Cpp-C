/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

string func(int x, int y, int h)
{
    if (x == 0 && y == 0)
        return "";
    if (abs(x) % 2 == abs(y) % 2)
        return "IMPOSSIBLE";
    if (h >= 50)
        return "IMPOSSIBLE";
    if (x % 2 == 0)
    {
        x /= 2;
        vector<pair<int, char>> can;
        can.push_back(make_pair((y - 1) / 2, 'N'));
        can.push_back(make_pair((y + 1) / 2, 'S'));
        pair<int, char> to;
        for (pair<int, char> t : can)
        {
            if (x == 0 && t.first == 0)
            {
                to = t;
                break;
            }
            if (abs(x) % 2 != abs(t.first) % 2)
                to = t;
        }
        string res = func(x, to.first, h + 1);
        if (res == "IMPOSSIBLE")
            return res;
        res.insert(res.begin(), to.second);
        return res;
    }
    if (y % 2 == 0)
    {
        y /= 2;
        vector<pair<int, char>> can;
        can.push_back(make_pair((x - 1) / 2, 'E'));
        can.push_back(make_pair((x + 1) / 2, 'W'));
        pair<int, char> to;
        for (pair<int, char> t : can)
        {
            if (y == 0 && t.first == 0)
            {
                to = t;
                break;
            }
            if (abs(y) % 2 != abs(t.first) % 2)
                to = t;
        }
        string res = func(to.first, y, h + 1);
        if (res == "IMPOSSIBLE")
            return res;
        res.insert(res.begin(), to.second);
        return res;
    }
    return "";
}

void solve()
{
    int x, y;
    cin >> x >> y;
    cout << func(x, y, 0) << "\n";
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
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}