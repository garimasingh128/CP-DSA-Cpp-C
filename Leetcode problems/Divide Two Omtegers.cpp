#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || ((dividend == INT_MIN) && (divisor == -1))) return INT_MAX;
        bool resNeg = (dividend < 0) ^ (divisor < 0);
        dividend = (0 < dividend) ? -dividend : dividend;
        if (divisor == INT_MIN) return dividend == INT_MIN;
        divisor= (0 < divisor) ? divisor: -divisor;
        if (dividend == INT_MIN) {
            for (int i=0; i<32; i++)
                if (divisor == (1 << i)) return INT_MIN >> i;
        }
        int res = 0;
        for (int ls=31; 0<=ls; ls--){
            if ((INT_MAX >> ls) < divisor) continue;
            int cur = divisor << ls;
            if (dividend + cur <= 0){
                dividend += cur;
                res += 1 << ls;
            }
        }
        return resNeg ? -res : res;
    }
};