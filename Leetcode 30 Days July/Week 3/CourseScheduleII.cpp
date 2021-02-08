class Solution {
public:
    vector<int> adj[100001];
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         int i,x,y,n;
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> v;
        for(i=0;i<prerequisites.size();i++)
        {
            x=prerequisites[i][0];
            y=prerequisites[i][1];
            adj[y].push_back(x);

            ++indegree[x];
        }
        for(i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            n=q.front();
            q.pop();
            v.push_back(n);
            for(auto j:adj[n])
            {
                --indegree[j];
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        if(v.size()==numCourses)
            return v;
        return {};
    }
};
