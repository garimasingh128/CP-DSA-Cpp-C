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

const int N = 105;

int n;
int a[N][N];

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        tc++;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int k = 0;
        for (int i = 1; i <= n; i++)
            k += a[i][i];
        int r = 0, c = 0;
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            set<int> s;
            for (int j = 1; j <= n; j++)
            {
                flag &= (s.find(a[i][j]) == s.end());
                s.insert(a[i][j]);
            }
            r += (!flag);
        }
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            set<int> s;
            for (int j = 1; j <= n; j++)
            {
                flag &= (s.find(a[j][i]) == s.end());
                s.insert(a[j][i]);
            }
            c += (!flag);
        }
        cout << "Case #" << tc << ": " << k << " " << r << " " << c << endl;
    }
    return 0;
}