#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string commonprefix(string s1,string s2){
        string result;
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0,j=0; i<n1 && j<n2; i++,j++){
            if(s1[i]!=s2[j]) break;
            else result.push_back(s1[i]);
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            prefix = commonprefix(strs[i],prefix);
        }
        return prefix;
    }
};