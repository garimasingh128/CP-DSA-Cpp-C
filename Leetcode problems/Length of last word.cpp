#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,m=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') c=0;
            if(isalpha(s[i])){
                c++;
                m=c;
            }  
        }
        return m;
    }
};