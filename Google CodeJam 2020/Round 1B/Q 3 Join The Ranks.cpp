/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

vector<pair<int, int>> st;

void add(pair<int, int> t)
{
    if (!st.empty() && st.back().first == t.first)
        st.back().second += t.second;
    else
        st.push_back(t);
}

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<pair<int, int>> ans;
    vector<pair<int, int>> a;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            a.push_back(make_pair(j, 1));
    while ((int)a.size() != r)
    {
        /*for (pair<int, int> t : a)
            cerr << t.first << " " << t.second << "\n";
        cerr << "\n";*/
        int p = 0;
        for (int i = 2; i < (int)a.size(); i++)
            if (a[0].first == a[i].first)
            {
                p = i;
                break;
            }
        if (p + 1 == (int)a.size())
        {
            int sum = 0;
            for (int i = 1; i <= p; i++)
                sum += a[i].second;
            ans.push_back(make_pair(a[0].second, sum));
            st.clear();
            for (int i = 1; i <= p; i++)
                add(a[i]);
            add(a[0]);
            a = st;
            continue;
        }
        int sum = 0;
        for (int i = 2; i <= p; i++)
            sum += a[i].second;
        ans.push_back(make_pair(a[0].second + a[1].second, sum));
        st.clear();
        for (int i = 2; i <= p; i++)
            add(a[i]);
        add(a[0]);
        add(a[1]);
        for (int i = p + 1; i < (int)a.size(); i++)
            add(a[i]);
        a = st;
    }
    if (a[0].first != 0)
    {
        int sum = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            if (a[i].first == 0)
                break;
            sum += a[i].second;
        }
        ans.push_back(make_pair(sum, r * c - sum));
    }
    cout << (int)ans.size() << "\n";
    for (pair<int, int> t : ans)
        cout << t.first << " " << t.second << "\n";
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