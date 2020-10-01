#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int number) {
        int num[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
        string sym[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
        int i=12;
        string res = "";
        while(number>0) { 
            int div = number/num[i]; 
            number = number%num[i]; 
            while(div--) res += sym[i];
            i--; 
        }
        return res;
    }
};