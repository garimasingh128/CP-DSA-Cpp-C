// ARTICULATION POINTS
#include<bits/stdc++.h>

using namespace std;

vector<int> ar[10001];
int visited[10001] , low[10001] , tin[10001];
vector<bool> isCutPoint(10001);
int timer ;
bool artPresent;

void dfs(int at , int parent = -1)
{
    visited[at] = 1;
    ++timer;
    low[at] = tin[at] = timer;
    int children = 0;

    for(int to : ar[at])
    {
        if(to == parent) continue;
        else if(visited[to])
          low[at] = min(low[at],tin[to]);
        else //if(!visited[to])
        {
            dfs(to,at);
            low[at] = min(low[at],low[to]);
            // articulation point find VIA bridge(<) or VIA cycle(==)
            if(tin[at]<=low[to]&&parent!=-1)
               artPresent = true , isCutPoint[at] = true;

            ++children;
        }
        if(parent==-1&&children>1)
           artPresent = true , isCutPoint[at] = true;
    }

}

int main()
{
    int n , m , a , b;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;
    cout<<"\nEnter the elements of graph: \n";
    while(m--)
      cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
    
    timer = 0;
    memset(visited,0,sizeof(visited));
    memset(tin,0,sizeof(tin));
    memset(low,0,sizeof(low));

    isCutPoint.assign(n,false);
    artPresent = false;

    for(int i=1;i<=n;++i)
      if(!visited[i])
         dfs(i);

    if(artPresent)
    {
        cout<<"\nArticulation Points are: ";
        for(int i=1;i<=n;++i)
          if(isCutPoint[i]) cout<<i<<" ";
    }
    else 
      cout<<"\n No Articulation point present";

    return 0;
}