#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        int sum=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]<prices[i]){
                int j=i-1;
                i++;
                while(i<n){
                    if(prices[i-1]<prices[i]) i++;
                    else break;
                }
                sum += (prices[i-1]-prices[j]);
            }
        }
        return sum;
    }
};