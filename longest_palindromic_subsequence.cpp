#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

/*
input:
abcghjba

output:
5
*/

int dp[100][100];

int LongestPalindromeSubsequence(string s, int start, int end)
{
  if(start>end)
  {
    return dp[start][end] = 0;
  }

  if(start==end)
  return dp[start][end] = 1;

  if(dp[start][end]!=-1)
  return dp[start][end];

  if(s[start]==s[end])
  {
    return dp[start][end] = 2 + LongestPalindromeSubsequence(s, start+1, end-1);
  }

  return dp[start][end] = max(LongestPalindromeSubsequence(s,start+1, end), LongestPalindromeSubsequence(s, start, end-1));
}

int32_t main()
{
  IOS;
  string s;
  cin>>s;
  memset(dp, -1, sizeof(dp));

  cout<<LongestPalindromeSubsequence(s, 0, s.length()-1);

  return 0;
}
