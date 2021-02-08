class Solution {
public:
    void dfs(int idx, int target, vector<int> &candidates, vector<int> &v, set<vector<int>> &st){
        int n=candidates.size();
        if(target==0){
            sort(v.begin(),v.end());
            st.insert(v);
            return;
        }
        if(idx==n) return;
        for(int i=idx;i<n;i++){
            if(candidates[i]>target) return;
            v.push_back(candidates[i]);
            dfs(i,target-candidates[i],candidates,v,st);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        set<vector<int>> st;
        int idx=0;
        dfs(idx,target,candidates,v,st);
        for(auto i:st) ans.push_back(i);
        return ans;
    }
};
