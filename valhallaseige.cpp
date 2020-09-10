#include <bits/stdc++.h>
typedef long long ll;
const int maxn = int(2e5) + 7;
ll a[maxn], k[maxn], sum[maxn], dmg;

int main() {
//    freopen("in.txt", "r", stdin);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= q; i++) scanf("%lld", k + i);
    for (int turn = 1, cur; turn <= q; turn++) {
        dmg += k[turn];
        if (dmg >= sum[n]) dmg = 0, printf("%d\n", n);
        else printf("%d\n", n - int(std::upper_bound(sum + 1, sum + 1 + n, dmg) - sum - 1));
    }
    return 0;
}
