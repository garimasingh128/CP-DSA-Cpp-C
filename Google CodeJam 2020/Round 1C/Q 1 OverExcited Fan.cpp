/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

const int INF = 1000000000;

int main()
{
    int tests;
    cin >> tests;
    for (int test_index = 0; test_index < tests; ++test_index)
    {
        int X, Y;
        cin >> X >> Y;
        string path;
        cin >> path;
        int ans = INF;
        for (int y = 0; y <= path.length(); ++y)
        {
            if (abs(X) + abs(Y) <= y)
            {
                ans = y;
                break;
            }
            if (y < path.length())
            {
                switch (path[y])
                {
                case 'N':
                    ++Y;
                    break;
                case 'S':
                    --Y;
                    break;
                case 'W':
                    --X;
                    break;
                case 'E':
                    ++X;
                    break;
                }
            }
        }
        cout << "Case #" << (test_index + 1) << ": ";
        if (ans < INF)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
