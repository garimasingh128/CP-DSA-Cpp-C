class Solution {
public:
    int maxProfit(vector<int>& price){
       int i=0,n=price.size();
       int profit=0,buy,sell;
       while(i<n-1)
       {
           while(i<n-1&&price[i+1]<=price[i])
           {
               i++;
           }
           if(i==n-1)
               break;
           buy=i++;
           while(i<n&&price[i]>=price[i-1])
               i++;
           sell=i-1;
           profit=profit+price[sell]-price[buy];
       }
        return profit;
    }
};