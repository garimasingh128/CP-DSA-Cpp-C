// FINDING BRIDGES IN UNDIRECTED GRAPH
#include<bits/stdc++.h>

using namespace std;

vector<int> ar[10001];
int visited[10001] , tin[10001] , low[10001];
vector<int> is_bridge;
int timer ;

void dfs(int at , int parent = -1)
{
    visited[at] = 1;
    ++timer;
    tin[at] = low[at] = timer;

    for(int to : ar[at])
    {
        if(to == parent) continue;
        else if(visited[to] && to!=parent)
           low[at] = min(low[at],tin[to]);
        else if(!visited[to])
        {
            dfs(to,at);
            low[at] = min(low[at],low[to]);
            if(low[to]>tin[at]) // bridge here
               is_bridge.push_back(at) , is_bridge.push_back(to);
        }
        
    }
}

int main()
{
    int n , m, a, b;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;
    cout<<"\nEnter the elements of graph:\n";
    while(m--)
      cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

    memset(visited,0,sizeof(visited));
    for(int i=0;i<=n;++i) tin[i] = 0 , low[i] = 0;

    timer = 0;
    for(int i=1;i<=n;++i)
    {
        if(!visited[i])
            dfs(i);
    }

    for(int i=1;i<=n;++i) cout<<low[i];

    cout<<"\nBridges in the given graph:\n";
    for(int i=0;i<is_bridge.size();i += 2)
       cout<<"There is a bridge from "<<is_bridge[i]<<" -> "<<is_bridge[i+1]<<endl;

    return 0;
}