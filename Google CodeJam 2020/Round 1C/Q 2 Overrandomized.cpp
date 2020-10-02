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

int main() {
  //FILE* f;
  //freopen_s(&f, "random.in", "r", stdin);
  int tests;
  cin >> tests;
  char buffer[100];
  for (int test_index = 0; test_index < tests; ++test_index) {
    int U;
    cin >> U;
    const int CNT = 10000;
    set<char> digits;
    set<char> was_first;
    map<char, int> freq;
    for (int i = 0; i < CNT; ++i) {
      ll q;
      string ni;
      cin >> q >> ni;
      was_first.insert(ni[0]);        
      /*if (ni.length() > U - 2) {
        continue;
      }*/
      for (int j = 0; j < ni.length(); ++j) {
        digits.insert(ni[j]);   
        //freq[ni[j]]++;
      }
      freq[ni[0]]++;
    }
    if (digits.size() != 10) {
      while (true) {
        cout << 1000 << endl;
      }
      abort();
    }
    /*if (was_first.size() != 9) {
      cerr << "WTF was_first size = " << was_first.size() << endl;
    }*/
    string ans = "";
    for (char c : digits) {
      if (!was_first.count(c)) {
        ans += c;
        break;
      }
    }
    vector<pair<int, char> > other;
    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
      if (it->first != ans[0]) {
        other.push_back(MP(it->second, it->first));
      }
    }
    sort(other.rbegin(), other.rend());
    for (int i = 0; i < other.size(); ++i) {
      ans += other[i].second;
      //cerr << other[i].second << ' ' << other[i].first << endl;
    }
    cout << "Case #" << (test_index + 1) << ": " << ans << endl;
  }
  return 0;
}
