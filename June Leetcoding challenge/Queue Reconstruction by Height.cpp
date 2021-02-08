class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans(n,vector<int>());
        for(int i=0;i<n;i++){
            int idx;
            for(int j=0,cnt=0;j<ans.size();j++){
                if(ans[j].empty()){
                    if(cnt==people[i][1]) {idx=j; break;}
                    cnt++;
                }
            }
            ans[idx]=people[i];
        }
        return ans;
    }
};
