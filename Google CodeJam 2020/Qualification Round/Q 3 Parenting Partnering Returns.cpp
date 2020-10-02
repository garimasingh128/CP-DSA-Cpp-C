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

const int N = 2005;

struct data
{
    int l, r;
    int idx;
};

int n;
data a[N];

bool comp(data &l, data &r)
{
    return l.l < r.l;
}

int f[N], s[N];
char ans[N];

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
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].l >> a[i].r;
            a[i].idx = i;
        }
        sort(a + 1, a + n + 1, comp);
        bool check = 1;
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            for (int j = a[i].l; j < a[i].r; j++)
                flag &= (f[j] == 0);
            if (flag)
            {
                for (int j = a[i].l; j < a[i].r; j++)
                    f[j]++;
                ans[a[i].idx] = 'C';
            }
            else
            {
                int flag = 1;
                for (int j = a[i].l; j < a[i].r; j++)
                    flag &= (s[j] == 0);
                if (flag)
                {
                    for (int j = a[i].l; j < a[i].r; j++)
                        s[j]++;
                    ans[a[i].idx] = 'J';
                }
                else
                {
                    check = 0;
                    break;
                }
            }
        }
        cout << "Case #" << tc << ": ";
        if (!check)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}