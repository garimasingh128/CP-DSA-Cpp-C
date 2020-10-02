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
        cout << "Case #" << qq << ":\n";
        int n;
        cin >> n;
        int rows = min(30, n);
        n -= rows;
        vector<int> a(rows);
        for (int row = rows - 1; row >= 0; row--)
        {
            if (n >= (1 << row) - 1)
            {
                a[row] = 1;
                n -= (1 << row) - 1;
            }
        }
        rows += n;
        a.resize(rows);
        int side = 0;
        for (int row = 0; row < rows; row++)
        {
            if (a[row] == 1)
            {
                if (side == 0)
                {
                    for (int j = 0; j <= row; j++)
                    {
                        cout << row + 1 << " " << j + 1 << '\n';
                    }
                }
                else
                {
                    for (int j = row; j >= 0; j--)
                    {
                        cout << row + 1 << " " << j + 1 << '\n';
                    }
                }
                side ^= 1;
            }
            else
            {
                if (side == 0)
                {
                    cout << row + 1 << " " << 1 << '\n';
                }
                else
                {
                    cout << row + 1 << " " << row + 1 << '\n';
                }
            }
        }
    }
    return 0;
}
