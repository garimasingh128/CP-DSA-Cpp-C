#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

typedef struct data
{
	data* bit[26];
	int cnt = 0;
}trie;

trie* head;

void insert(string &s)
{
	trie* cur = head;
	for(auto &it:s)
	{
		int b = it - 'A';
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

int n, k;
string s[N];

int query(trie* cur, int lvl)
{
	if(!cur)
		return 0;
	int ans = (cur -> cnt / k);
	for(int i = 0; i <= 25; i++)
		if(cur -> bit[i])
			ans += query(cur -> bit[i], lvl + 1);
	return ans;
}
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0; 
	while(t--)
	{
		head = new trie();
		tc++;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			insert(s[i]);
		}
		int ans = query(head, 0);
		cout << "Case #" << tc << ": " << ans << endl;
 	}	
	return 0;
}