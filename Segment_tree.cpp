#include <bits/stdc++.h>
using namespace std;

class segment_tree
{
    int base = 1;
    int *tree;
    int *low;
    int *high;
    int def;

    // uncomment required line
    int fun(int a, int b)
    {
        return max(a, b);
        // return min(a, b);
        // return a+b;
    }

public:
    segment_tree(vector<int> arr)
    {

        // set default return value

        def = 0; // for max
        // def = INT64_MAX; // for min
        // def = 0; // for sum

        int size = arr.size();
        while (size > base)
            base <<= 1;
        tree = new int[2 * base];
        for (int i = 0; i < size; i++)
            tree[base + i] = arr[i];
        for (int i = base - 1; i > 0; i--)
            tree[i] = fun(tree[2 * i], tree[2 * i + 1]);

        low = new int[2 * base];
        high = new int[2 * base];

        for (int i = 0; i < base; i++)
            high[base + i] = low[base + i] = i;

        for (int i = base - 1; i > 0; i--)
        {
            low[i] = low[2 * i];
            high[i] = high[2 * i + 1];
        }
    }

    void update(int index, int value)
    {
        tree[base + index] = value;
        int i = (base + index) / 2;
        while (i > 0)
            tree[i] = fun(tree[2 * i], tree[2 * i + 1]), i >> 2;
    }

    int query(int a, int b, int i = 1)
    {
        int ans;
        if (a <= low[i] and b >= high[i])
            ans = tree[i];
        else if (a > high[i] or b < low[i])
            ans = def;
        else
            ans = fun(query(a, b, 2 * i + 1), query(a, b, 2 * i));
        return ans;
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    segment_tree st(v);
    cout << st.query(1, 5) << endl;
    st.update(3, 100);
    cout << st.query(1, 5) << endl;

}
