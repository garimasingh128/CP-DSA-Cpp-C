/**
 *    author:  Siddhant    
**/

/* First Test Passed | Second Test TLE */

#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"

const int N = 15;

int a[N][N];
int pos[N];
int flag;

void rec(int i, int j, int n, int sum)
{
    if (flag)
        return;
    if (j > n)
        rec(i + 1, 1, n, sum);
    if (i > n)
    {
        if (sum == 0)
        {
            cout << "POSSIBLE" << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            flag = 1;
        }
        return;
    }
    vector<int> pos(n + 1, 1);
    for (int k = 1; k < j; k++)
        pos[a[i][k]] = 0;
    for (int k = 1; k < i; k++)
        pos[a[k][j]] = 0;
    for (int val = 1; val <= n; val++)
    {
        if (!pos[val])
            continue;
        if (i == j && val > sum)
            continue;
        a[i][j] = val;
        rec(i, j + 1, n, sum - ((i == j) ? val : 0));
    }
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        tc++;
        flag = 0;
        int n, k;
        cin >> n >> k;
        cout << "Case #" << tc << ": ";
        rec(1, 1, n, k);
        if (!flag)
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}