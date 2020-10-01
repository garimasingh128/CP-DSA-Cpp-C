/*

Created on : 2020-09-12 21:54:44
author name : archit nitin latkar

*/

#include<iostream>
#include<bits/stdc++.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class UnionFind{
    int size;
    vi id;
    vi csize;
    int ncomponents;

    public:
    
    UnionFind(int size){
        this->size = size;
        id.resize(size);
        csize.resize(size);
        for(int i=0;i<size;i++){
            id[i] = i;
            csize[i] = 1;
        }
        ncomponents = size;
    }

    int find(int x){
        int root = x;
        while(root != id[root]) root = id[root];
        while(x!=root){
            int parent = id[x];
            id[x] = root;
            x = parent;
        }
        return root;
    }

    bool isconnected(int x, int y){
        return find(x) == find(y);
    }

    int componentSize(int x){
        return csize[find(x)];
    }

    int components(){
        return ncomponents;
    }

    bool unite(int x, int y){ // generally void, but since i need to add weight, i am making it bool
        int r1 = find(x);
        int r2 = find(y);
        if(r1 == r2) return false;
        else if(csize[r1] > csize[r2]){
            csize[r1] += csize[r2];
            id[r1] = r2;
        }
        else{
            csize[r2] += csize[r1];
            id[r2] = r1;
        }
        ncomponents--;
        return true;
    }


};
// Use Union Find to implement Kruskal's Algorithm
// void solve(){

// }

int main(){
    
    int n;
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges: ";
    int e;
    cin>>e;
    cout<<"Enter edges: vertex1 vertex2 weight\n";
    //vector<vector<pair<int,int>>> graph;
    vector<tuple<int,int,int>> edgeList;
    //graph.resize(n);
    for(int i=0;i<e;i++){
        int s, d, w;
        cin>>s>>d>>w;
        // graph[s].push_back(make_pair(d,w));
        // graph[d].push_back(make_pair(s,w));
        edgeList.push_back(make_tuple(w,s,d));
    }
    sort(edgeList.begin(), edgeList.end());
    UnionFind disjoint_set(n);
    int ans = 0;
    for(int i=0;i<edgeList.size();i++){
        if(disjoint_set.unite(get<1>(edgeList[i]), get<2>(edgeList[i]))){
            ans += get<0>(edgeList[i]);
        }
    }
    cout<<"answer: "<<ans<<endl;
    return 0;
}
