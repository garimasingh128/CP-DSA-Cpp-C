#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string>map = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
    
    void helper(int idx, string temp, string &digits, vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        int total = map[digits[idx]-'1'].size();
        for(int i = 0;i<total;i++) helper(idx+1,temp+map[digits[idx]-'1'][i], digits,ans);
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> ans;
        int total = map[digits[0]-'1'].size(), idx = 0;
        for(int i = 0;i<total;i++){
            string s = "";
            s+=map[digits[0]-'1'][i];
            helper(idx+1,s, digits, ans);
        }
        return ans;
    }
};