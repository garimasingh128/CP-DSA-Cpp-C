#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[256];
        memset(count,0,sizeof(count));
        for(int i=0;i<s.length();i++) count[s[i]]++;
        for(int i=0;i<s.length();i++) if(count[s[i]]==1) return i;
        return -1;
    }
};