#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

/**
 * Description: Fast flow. After computing flow, edges ${u,v}$ such that 
	* $level[u] \neq -1,$ $level[v] = -1$ are part of min cut.
 * Time: $O(N^2M)$ flow, $O(M\sqrt N)$ bipartite matching
 * Source: GeeksForGeeks, Chilli
 * Verification: RMI 2017 Day 1 Fashion
	* https://pastebin.com/VJxTvEg1
 */

template<int SZ> struct Dinic {
	int N,s,t; // # verts, source, sink
	typedef ll F; // flow type
	struct Edge { int to, rev; F flow, cap; };
	vector<Edge> adj[SZ];
	void ae(int u, int v, F cap) {
		assert(cap >= 0); // don't try smth dumb
		Edge a{v,sz(adj[v]),0,cap}, b{u,sz(adj[u]),0,0};
		adj[u].pb(a), adj[v].pb(b);
	}
	int level[SZ]; typename vector<Edge>::iterator cur[SZ]; 
	bool bfs() { // level = shortest distance from source
		F0R(i,N) level[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); level[s] = 0; 
		while (sz(q)) {
			int u = q.ft; q.pop();
			trav(e,adj[u]) if (level[e.to] < 0 && e.flow < e.cap) 
				q.push(e.to), level[e.to] = level[u]+1;
		}
		return level[t] >= 0;
	}
	F sendFlow(int v, F flow) {
		if (v == t) return flow;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (level[e.to]!=level[v]+1||e.flow==e.cap) continue;
			auto df = sendFlow(e.to,min(flow,e.cap-e.flow));
			if (df) { // saturated at least one edge
				e.flow += df; adj[e.to][e.rev].flow -= df;
				return df;
			}
		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; assert(s != t);
		F tot = 0; while (bfs()) while (F df = 
			sendFlow(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

// REINITIALIZE ARRAYS BETWEEN TCs

int N,K;

void inp(vi& v) { // common way to reduce amount of input
	v.rsz(1); ll A,B,C; re(v,A,B,C);
	while (sz(v) < N) v.pb((A*v.back()+B)%C+1);
}

void chk(vector<vi> v) {
	F0R(i,N) F0R(j,N) if (!(1 <= v[i][j] && v[i][j] <= N)) exit(5);
	F0R(i,N) {
		set<int> s(all(v[i]));
		if (sz(s) < N) exit(5);
	}
	F0R(i,N) FOR(j,i+1,N) swap(v[i][j],v[j][i]);
	F0R(i,N) {
		set<int> s(all(v[i]));
		if (sz(s) < N) exit(5);
	}
	int sum = 0;
	F0R(i,N) sum += v[i][i];
	assert(sum == K);
}

void fill(vector<vi>& v) {
	//dbg("FILL");
	FOR(i,1,N+1) {
		bool found = 0;
		F0R(j,N) if (v[0][j] == i) found = 1;
		//dbg("FOUND",i,found);
		if (found) continue;
		// ps("FILL");
		Dinic<105> D;
		F0R(a,N) {
			D.ae(0,1+a,1);
			D.ae(N+1+a,2*N+1,1);
		}
		F0R(a,N) F0R(b,N) if (!v[a][b]) {
			//dbg("??",1+a,N+1+b);
			D.ae(1+a,N+1+b,1);
		}
		//dbg("START",v);
		assert(D.maxFlow(2*N+2,0,2*N+1) == N);
		//dbg("WUT");
		FOR(a,1,N+1) trav(t,D.adj[a]) if (t.flow > 0) {
			//dbg("ED",a,t.to);
			v[a-1][t.to-N-1] = i;
		}
		//dbg("CUR",v);
	}
	//dbg("OK",v);
}

void place(int a, int b, int c) { // a twice, b once, c rest
	assert(N >= 4);
	vector<vi> res(N,vi(N));
	res[0][0] = res[1][1] = a;
	res[2][2] = b;
	FOR(i,3,N) res[i][i] = c;
	if (N == 4) {
		res[2][3] = res[3][2] = a;
		res[0][1] = res[1][3] = res[3][0] = b;
		res[0][2] = res[1][0] = res[2][1] = c;
	} else {
		if (N <= 6) {
			if (N == 5) {
				res[3][2] = res[2][4] = res[4][3] = a;
				res[0][2] = res[1][0] = res[2][1] = c;
				res[0][1] = res[1][3] = res[3][4] = res[4][0] = b;
				//dbg("HUH");
				//trav(t,res) dbg(t);
			} else {
				res[2][3] = res[3][4] = res[4][5] = res[5][2] = a;
				res[0][2] = res[1][0] = res[2][1] = c;
				res[0][1] = res[1][5] = res[3][0] = res[4][3] = res[5][4] = b;
				//dbg("??",N,K,a,b,c);
				//exit(0);
			}
		} else {
			res[2][3] = res[3][2] = a;
			res[0][1] = res[1][3] = res[3][0] = b;
			res[0][2] = res[1][0] = res[2][1] = c;
			F0R(i,N-4) {
				res[i+4][(i+1)%(N-4)+4] = a;
				res[i+4][(i+2)%(N-4)+4] = b;
			}
		}
	}
	fill(res);
	chk(res);
	F0R(i,N) {
		F0R(j,N) pr(res[i][j],' ');
		ps();
	}
}

void solve(int caseNum) {
	// cerr << "Doing #" << caseNum << "\n";
	if (K == N+1 || K == N*N-1) {
		ps("IMPOSSIBLE");
		return;
	}
	if (N == 3) {
		if (K == 5 || K == 7) {
			ps("IMPOSSIBLE");
			return;
		}
	}
	ps("POSSIBLE");
	int x = K/N; int b = K-N*x; int a = N-b;
	if (a == 1 || b == 1) {
		if (a == 1) {
			// x, x+1, x+1, ...
			// x, x, x+2, x+1, x+1, ...
			place(x,x+2,x+1);
		} else {
			// x, x, x, ..., x+1
			// x-1, x, x, ..., x+1, x+1
			place(x+1,x-1,x);
		}
		return;
	}
	vector<vi> res(N,vi(N));
	F0R(i,N) {
		if (i < a) res[i][i] = x;
		else res[i][i] = x+1;
	}
	if (b) {
		F0R(i,a) res[(i+1)%a][i] = x+1;
		F0R(i,b) res[(i+1)%b+a][i+a] = x;
	}
	fill(res);
	chk(res);
	//ps("OH");
	F0R(i,N) {
		F0R(j,N) pr(res[i][j],' ');
		ps();
	}
}

int main() {
	// setIO("A");
	/*FOR(_N,2,6) FOR(_K,_N,_N*_N+1) {
		N = _N, K = _K;
		solve(0);
	}*/
	//dbg("OK");
	//exit(0);
	int T; re(T);
	FOR(i,1,T+1) {
		pr("Case #",i,": ");
		re(N,K);
		solve(i);
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/

