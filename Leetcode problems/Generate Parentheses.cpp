#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) res.push_back("");
        else{
            for(int c=0;c<n;c++){
                for(string left: generateParenthesis(c)){
                    for(string right: generateParenthesis(n-1-c)) res.push_back("("+left+")"+right);
                }
            }
        }
        return res;
    }
};