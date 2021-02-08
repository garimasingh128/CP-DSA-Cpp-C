class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int i,j;
        map<vector<int>,vector<string> > m;
        vector<vector<string> > v;
        string s;
        for(i=0;i<strs.size();i++)
        {
            s=strs[i];
            vector<int> f(26,0);
            for(j=0;j<s.length();j++)
            {
                f[s[j]-'a']++;
            }
             m[f].push_back(s);
        }
        for(auto z:m)
        {
            v.push_back(z.second);
        }
        return v;
        }
};
