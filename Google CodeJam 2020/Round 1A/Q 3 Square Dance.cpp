/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++)
    {
        cout << "Case #" << qq << ": ";
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> when(h, vector<int>(w, -1));
        vector<vector<int>> up(h, vector<int>(w));
        vector<vector<int>> down(h, vector<int>(w));
        vector<vector<int>> left(h, vector<int>(w));
        vector<vector<int>> right(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                up[i][j] = i - 1;
                down[i][j] = i + 1;
                left[i][j] = j - 1;
                right[i][j] = j + 1;
            }
        }
        auto GetNeighbor = [&](pair<int, int> p, int dir) {
            if (dir == 0)
                return make_pair(up[p.first][p.second], p.second);
            if (dir == 1)
                return make_pair(down[p.first][p.second], p.second);
            if (dir == 2)
                return make_pair(p.first, left[p.first][p.second]);
            return make_pair(p.first, right[p.first][p.second]);
        };
        long long total = 0;
        vector<pair<int, int>> check;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                total += a[i][j];
                check.emplace_back(i, j);
            }
        }
        long long ans = total;
        for (int iter = 0;; iter++)
        {
            vector<pair<int, int>> rm;
            for (auto &p : check)
            {
                int sum = 0;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    auto q = GetNeighbor(p, dir);
                    int qi = q.first;
                    int qj = q.second;
                    if (qi >= 0 && qj >= 0 && qi < h && qj < w)
                    {
                        sum += a[qi][qj];
                        cnt += 1;
                    }
                }
                if (sum > a[p.first][p.second] * cnt)
                {
                    rm.push_back(p);
                }
            }
            if (rm.empty())
            {
                break;
            }
            for (auto &p : rm)
            {
                when[p.first][p.second] = iter;
                total -= a[p.first][p.second];
            }
            ans += total;
            vector<pair<int, int>> new_check;
            for (auto &p : rm)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    auto q = GetNeighbor(p, dir);
                    int qi = q.first;
                    int qj = q.second;
                    if (qi >= 0 && qj >= 0 && qi < h && qj < w)
                    {
                        if (when[qi][qj] != iter)
                        {
                            new_check.emplace_back(qi, qj);
                            when[qi][qj] = iter;
                        }
                    }
                }
            }
            for (auto &p : rm)
            {
                int i = p.first;
                int j = p.second;
                if (up[i][j] != -1)
                {
                    down[up[i][j]][j] = down[i][j];
                }
                if (down[i][j] != h)
                {
                    up[down[i][j]][j] = up[i][j];
                }
                if (left[i][j] != -1)
                {
                    right[i][left[i][j]] = right[i][j];
                }
                if (right[i][j] != w)
                {
                    left[i][right[i][j]] = left[i][j];
                }
            }
            swap(check, new_check);
        }
        cout << ans << '\n';
    }
    return 0;
}
