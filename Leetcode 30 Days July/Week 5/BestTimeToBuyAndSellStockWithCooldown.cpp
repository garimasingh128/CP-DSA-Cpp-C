class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int p0=0,p1=INT_MIN,pre=0;

        for(auto price:prices)
        {
            int old=p0;
            p0=max(p0,p1+price);
            p1=max(p1,pre-price);
            pre=old;
        }

        return p0;

    }
};
