#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int n=digits.size();
        int carry=0;
        for(int i=n-1;i>=0;i--) {
            int c=digits[i]+carry;
            if(i==n-1) c+=1;
            if(c==10) {
                carry=1;
                v.push_back(0);
            }
            else{
                v.push_back(c);
                carry=0;
            }
        }
        if(carry==1) v.push_back(carry);
        reverse(v.begin(),v.end());
        return v;
    }
};