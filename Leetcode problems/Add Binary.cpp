#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        string s="";
        int i=n-1,j=m-1,carry=0;
        while(i>=0||j>=0||carry)
        {
            carry+=(i>=0)?a[i--]-'0':0;
            carry+=(j>=0)?b[j--]-'0':0;
            s+=carry%2+'0';
            carry/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};