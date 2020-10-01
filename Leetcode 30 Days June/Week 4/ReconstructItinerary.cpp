class Solution {
public:
    void dfs(string s,unordered_map<string,vector<string>> &v,vector<string> &f)
    {
        while(!v[s].empty())
        {
            string t=v[s].back();
            v[s].pop_back();
            dfs(t,v,f);
        }
        f.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> v;
        vector<string> f;
       for(int i=0;i<tickets.size();i++)
       {
           v[tickets[i][0]].push_back(tickets[i][1]);
       }
       for(auto &j:v)
       {
           sort(j.second.begin(),j.second.end(),greater<string>());
       }
        dfs("JFK",v,f);
        reverse(f.begin(),f.end());
        return f;
    }
};
