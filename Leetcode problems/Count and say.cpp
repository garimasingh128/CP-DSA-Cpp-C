#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        int cnt=1;
        while(--n){
            string res="";
            for(int i=0;i<s.length();++i){
                if(s[i]==s[i+1]) cnt++;
                else{
                    res = res + to_string(cnt)+s[i];
                    cnt = 1;
                }
            }
            s=res;
        }
        return s;
    }
};