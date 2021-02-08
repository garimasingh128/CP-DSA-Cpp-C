#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0,i=0;
        vector<int> arr(256,-1);
        for(int j=0;j<s.length();j++){
            i = max(i,arr[s[j]]+1);
            res = max(res,j-i+1);
            arr[s[j]] = j;
        }
        return res;
    }
};