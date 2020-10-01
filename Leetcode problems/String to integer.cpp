#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        str.append("lawda mera");
        stringstream ss;
        ss<<str;
        int x;
        ss>>x;
        return x;
    }
};