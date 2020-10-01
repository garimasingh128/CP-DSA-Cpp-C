class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int i,b,s,f=0,n=prices.size();
        i=0;
        while(i<n-1)
        {
            while(i<n-1 && prices[i]>=prices[i+1])
                i++;

            b=i;
            i++;
            while(i<n && prices[i]>=prices[i-1])
                i++;
            s=i-1;
            f+=prices[s]-prices[b];
            //cout << b << " " << s;
        }
        return f;

    }
};
