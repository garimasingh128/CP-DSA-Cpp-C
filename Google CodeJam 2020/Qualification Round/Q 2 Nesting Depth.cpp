#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 205;

int n;
string s;
int open[N], close[N];

bool check(string &s)
{
    for (auto &it : s)
        if (it > '0')
            return 1;
    return 0;
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
        cin >> s;
        string str = s;
        n = s.size();
        memset(open, 0, sizeof(open));
        memset(close, 0, sizeof(close));
        while (check(s))
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    continue;
                int j = i;
                while (j + 1 < n && s[j + 1] > '0')
                    j++;
                open[i]++;
                close[j + 1]++;
                for (int k = i; k <= j; k++)
                    s[k]--;
                break;
            }
        }
        cout << "Case #" << tc << ": ";
        for (int i = 0; i < n; i++)
        {
            while (close[i]--)
                cout << ")";
            while (open[i]--)
                cout << "(";
            cout << str[i];
        }
        while (close[n]--)
            cout << ")";
        cout << endl;
    }
    return 0;
}