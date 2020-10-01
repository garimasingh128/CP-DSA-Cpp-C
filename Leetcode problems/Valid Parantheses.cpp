#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) return false;
            else{
                char x = st.top();
                st.pop();
                if(s[i]==')' && x!='(') return false;
                else if(s[i]==']' && x!='[') return false;
                else if(s[i]=='}' && x!='{') return false;
            }
        }
        return st.empty();
    }
};