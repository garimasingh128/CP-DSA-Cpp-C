/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>
using namespace std;

//#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 205;

int n, si, sj, di, dj, state, ct;
int a[N], b[N];

int ask(int idx)
{
    cout << idx << endl;
    assert(idx <= n);
    char ch;
    cin >> ch;
    assert(ch != 'N');
    return ch - '0';
}

void output()
{
    string ans = "";
    for (int i = 1; i <= n; i++)
        ans += (char)(a[i] + '0');
    cout << ans << endl;
    char ch;
    cin >> ch;
    assert(ch != 'N');
}

int32_t main()
{
    int t;
    cin >> t >> n;
    while (t--)
    {
        memset(a, -1, sizeof(a));
        int i = 1, j = n;
        state = ct = 0;
        si = di = sj = dj = -1;
        while (i < j)
        {
            ct += 2;
            if (ct > 10 && ct % 10 == 2)
            {
                bool complement = 0, reverse = 0;
                if (si > 0)
                {
                    ct++;
                    b[si] = ask(si);
                    if (b[si] == !a[si])
                        complement = 1;
                }
                if (complement)
                    for (int i = 1; i <= n; i++)
                        if (a[i] != -1)
                            a[i] = !a[i];
                if (di > 0)
                {
                    ct++;
                    b[di] = ask(di);
                    if (b[di] == a[dj])
                        reverse = 1;
                }
                if (reverse)
                    for (int i = 1, j = n; i < j; i++, j--)
                        swap(a[i], a[j]);
                if (ct % 2)
                {
                    a[i] = ask(i);
                    ct++;
                }
            }
            a[i] = ask(i);
            a[j] = ask(j);
            if (a[i] == a[j])
                si = i, sj = j;
            if (a[i] != a[j])
                di = i, dj = j;
            i++;
            j--;
        }
        output();
    }
    return 0;
}