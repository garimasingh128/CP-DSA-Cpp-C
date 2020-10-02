#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector <int> A[MAXN], G[MAXN];
int cval, val[MAXN], ctr[MAXN];
void label_tree(int pos)
{
	if(G[pos].size() >= 1)
		label_tree(G[pos][0]);
	val[pos] = cval;
	++cval;
	if(G[pos].size() >= 2)
		label_tree(G[pos][1]);
}
void print_tree(int pos)
{
	cout<<val[pos]<<" ";
	for (int i = 0; i < G[pos].size(); ++i)
	{
		print_tree(G[pos][i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		long long int curr = 0;
		int ptr = 1;
		for (int i = 0; i < n; ++i)
		{
			ctr[i] = 1;
			curr+=i;
		}
		for (int i = n - 1; i > ptr && curr > c; --i)
		{
			int max_reduce = i - ptr;
			int to_reduce = min(max_reduce*1ll, curr - c);
			curr-=to_reduce;
			ctr[i] = 0;
			ctr[i - to_reduce]++;
			if(ctr[ptr] == 2*ctr[ptr - 1])
				ptr++;
		}
		if(curr != c)
		{
			cout<<"-1\n";
			continue;
		}
		cval = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < ctr[i]; ++j)
			{
				A[i].push_back(cval);
				++cval;
			}
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < ctr[i]; ++j)
			{
				G[A[i-1][j/2]].push_back(A[i][j]);
			}
		}
		cval = 1;
		label_tree(0);
		print_tree(0);
		cout<<"\n";
		// cleanup
		for (int i = 0; i < n; ++i)
		{
			A[i].clear();
			G[i].clear();
		}
	}
	return 0;
}
