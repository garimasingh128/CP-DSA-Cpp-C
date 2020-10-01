class Solution {
public:
    bool vis(int v, vector<int> &path)
    {
        for(auto i: path)
            if(i == v)
                return true;
        return false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int src = 0, des = graph.size()-1;
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(src);
        queue<vector<int>> q;
        q.push(path);
        while(!q.empty())
        {
            path = q.front();
            q.pop();
            int last_val = path.back();
            if(last_val == des)
                res.push_back(path);
            for(auto v: graph[last_val])
            {
                if(!vis(v, path))
                {
                    vector<int> temp(path);
                    temp.push_back(v);
                    q.push(temp);
                }
            }
        }
        return res;
    }
};
