#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int>* adj;
    void countPathsUtil(int, int, int&);

public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

int Graph::countPaths(int s, int d)
{
    int pathCount = 0;
    countPathsUtil(s, d, pathCount);
    return pathCount;
}

void Graph::countPathsUtil(int u, int d,
                           int& pathCount)
{
    if (u == d)
        pathCount++;
    else {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            countPathsUtil(*i, d, pathCount);
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    int s = 0, d = 4;
    cout << g.countPaths(s, d);

    return 0;
}
