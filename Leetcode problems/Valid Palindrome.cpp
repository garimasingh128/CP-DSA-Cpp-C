#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.length();i++) if(isalnum(s[i])) res += s[i];
        int i=0,j=res.length()-1;
        while(i<j) if(tolower(res[i++])!=tolower(res[j--])) return false;
        return true;
    }
};