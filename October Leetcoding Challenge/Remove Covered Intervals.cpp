class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size(),ans=1;
        if(n==0) return 0;
        int l=intervals[0][0],r=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=l && intervals[i][1]<=r) continue;
            else{
                ans++;
                l=min(l,intervals[i][0]);
                r=max(r,intervals[i][1]);
            }
        }
        return ans;
    }
};
