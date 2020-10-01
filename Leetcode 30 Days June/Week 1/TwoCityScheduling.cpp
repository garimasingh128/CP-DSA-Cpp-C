class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {


        int f=0,i;

        sort(costs.begin(),costs.end(),[](vector<int>& a,vector<int>& b)-> bool{ return a[1]-a[0]>b[1]-b[0]; });

        for(i=0;i<costs.size();i++)
        {
            if(i<(costs.size()/2))
                f+=costs[i][0];
            else
                f+=costs[i][1];
        }
        return f;
    }
};
