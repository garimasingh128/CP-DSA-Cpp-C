class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        int i,n;
        priority_queue<pair<int,int> > v;
        vector<int> f;
        unordered_map<int,int> m;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto j:m)
        {
            v.push(make_pair(j.second,j.first));
        }
        for(i=0;i<k;i++)
        {
            n=v.top().second;
            f.push_back(n);
            v.pop();
        }
        return f;
    }
};
