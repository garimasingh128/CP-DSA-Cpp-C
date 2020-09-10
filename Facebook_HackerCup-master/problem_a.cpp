#include <bits/stdc++.h>
#include <climits>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define sci(x) int x; scanf("%d", &x);
#define scll(x) LL x; scanf("%lld", &x);
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
#define PB push_back
#define MP make_pair
using namespace std;
typedef unsigned int UI; 
typedef long int LI; 
typedef unsigned long int ULI; 
typedef long long int LL; 
typedef unsigned long long int ULL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef deque<int> DI;
typedef deque<LL> DLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const LL MOD = 1e9+7;

/* Fast I/O */
inline int scanInt() {
	int n = 0;
	char ch = getchar();
	int sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(int)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

inline LL scanLong() {
	LL n = 0;
	char ch = getchar();
	LL sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(LL)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

int main() {
	sll(t);
	rep(c, 1, t+1) {
		cout << "Case #" << c << ":\n"; 
		sll(n);
		string in, out;
		cin >> in >> out;
		bool move[n][n]; clr(move);
		rep(i, 0, n) {
			rep(j, 0, n) {
				if(i == j)	move[i][j] = true;
				else if(i < j) {
					move[i][j] = (out[i] == 'Y' && in[j] == 'Y');
					rep(k, i+1, j) {
						move[i][j] = move[i][j] && (in[k] == 'Y' && out[k] == 'Y');
						
					}
				}
				else if(i > j) {
					move[i][j] = (out[i] == 'Y' && in[j] == 'Y');
					rep(k, j+1, i) {
						move[i][j] = move[i][j] && (in[k] == 'Y' && out[k] == 'Y');
					}
				}
			}
		}

		rep(i, 0, n) {
			rep(j, 0, n) {
				cout << (move[i][j] ? 'Y' : 'N');
			}
			cout << endl;
		}
	}
}