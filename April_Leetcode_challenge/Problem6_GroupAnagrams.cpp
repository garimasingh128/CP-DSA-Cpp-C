class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0; i<strs.size();i++)
        {
            string value = strs[i];
            sort(value.begin(),value.end());
            mp[value].push_back(strs[i]);
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};