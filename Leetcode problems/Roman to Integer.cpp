#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int values(char c) {
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        return 1000; 
    }
    
public:
    int romanToInt(string s) {
        int ans=0,i;
        for(i=0;i<s.length()-1;i++) {
            if(values(s[i])>=values(s[i+1])) ans+=values(s[i]);
            else ans-=values(s[i]);
        }
        ans+=values(s[i]);
        return ans;
    }
};