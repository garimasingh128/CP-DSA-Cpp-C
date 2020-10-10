class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                if(mp.find(nums[i]-k)!=mp.end()) ans++;
                if(mp.find(nums[i]+k)!=mp.end()) ans++;
            }
            mp[nums[i]]++;
        }
        if(k==0){
            for(auto i:mp){
                if(i.second>=2) ans++;
            }
        }
        return ans;
    }
};
