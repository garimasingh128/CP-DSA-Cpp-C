#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fathers[100];
 
int find(int x){
    if(fathers[x] == x){
        return x;
    }
    return find(fathers[x]);
}
 
void unite(int x, int y){
    int fx = find(x);
    int fy = find(y);
    fathers[fx] = fy;
}
 
int main(){
    for(int i=0;i<100;i++){
        fathers[i]=i;
    }
    int n,m;
    int a,b,w;
    vector < pair < int , pair < int , int > > > edges;
    cout<<"enter value of n- no of vertex & m-no of edges \n";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges.push_back(make_pair( w,make_pair(a,b) ) );
    }
    cout<<endl;
    int mst_weight = 0, mst_edges = 0;
    int mst_ni = 0;
    sort(edges.begin(),edges.end());
    while( ( mst_edges < n-1) || (mst_ni < m) ){
        a = edges[mst_ni].second.first;
        b = edges[mst_ni].second.second;
        w = edges[mst_ni].first;
        if( find(a) != find(b) ) {
            unite(a,b);
            mst_weight += w;
            cout<<a<<" "<<b<<" "<<w<<endl;
            mst_edges++;
        }
        mst_ni++;
    }
    cout<<"\nWeight of the MST is "<<mst_weight<<endl;

}
 
