/**
 *    author:  Siddhant    
**/

#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

const int INF = 1000000000;

ll gcd(ll a, ll b)
{
    if (!b)
    {
        return a;
    }
    return gcd(b, a % b);
}

struct Rational
{
    ll p, q;

    Rational(ll p_, ll q_)
    {
        ll g = gcd(p_, q_);
        p = p_ / g;
        q = q_ / g;
    }
};

bool operator<(const Rational &a, const Rational &b)
{
    return a.p * b.q < a.q * b.p;
}

int main()
{
    int tests;
    cin >> tests;
    for (int test_index = 0; test_index < tests; ++test_index)
    {
        int N, D;
        cin >> N >> D;
        int ans = D - 1;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        map<Rational, vi> cut_to;
        for (int i = 0; i < N; ++i)
        {
            for (int cuts = 1; cuts <= D; ++cuts)
            {
                Rational S(A[i], cuts);
                cut_to[S].push_back(cuts);
            }
        }
        sort(A.begin(), A.end());
        int first_bigger = 0;
        for (map<Rational, vi>::iterator it = cut_to.begin(); it != cut_to.end(); ++it)
        {
            Rational S = it->first;
            ll total = 0;
            for (int i = first_bigger; i < A.size(); ++i)
            {
                if (A[i] * S.q < S.p)
                {
                    ++first_bigger;
                }
                total += A[i] * S.q / S.p;
                if (total >= D)
                {
                    break;
                }
            }
            if (total < D)
            {
                break;
            }
            vi cuts_cnt = it->second;
            vector<int> min_cuts(D + 1, INF);
            min_cuts[0] = 0;
            for (int i = 0; i < cuts_cnt.size(); ++i)
            {
                int c = cuts_cnt[i];
                for (int j = D - c; j >= 0; --j)
                {
                    if (min_cuts[j + c] > min_cuts[j] + c - 1)
                    {
                        min_cuts[j + c] = min_cuts[j] + c - 1;
                    }
                }
            }
            for (int pieces = 2; pieces <= D; ++pieces)
            {
                if (ans > min_cuts[pieces] + D - pieces)
                {
                    ans = min_cuts[pieces] + D - pieces;
                }
            }
        }
        cout << "Case #" << (test_index + 1) << ": " << ans << endl;
    }
    return 0;
}
