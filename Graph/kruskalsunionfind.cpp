#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
//  Disjoint Sets Data Structure
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
    //  initialize fathers for the disjoint sets
    for(int i=0;i<100;i++){
        fathers[i]=i;
    }
    //  declaring the variables to load input
    int n,m;
    int a,b,w;
    vector < pair < int , pair < int , int > > > edges;
    //  loading the input
    cout<<"enter value of n- no of vertex & m-no of edges \n";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges.push_back(make_pair( w,make_pair(a,b) ) );
    }
    //  we print a line to separate input from output
    cout<<endl;
    //  NOW THE KRUSKAL'S ALGORITHM BEGINS
    //  We firstly declare the variables for the MST
    int mst_weight = 0, mst_edges = 0;
    int mst_ni = 0;
    //  STEP 1: sort the list of edges
    sort(edges.begin(),edges.end());
    //  STEP 2-3:
    while( ( mst_edges < n-1) || (mst_ni < m) ){
        //  we brake the edge into the three integers they describe it
        a = edges[mst_ni].second.first;
        b = edges[mst_ni].second.second;
        w = edges[mst_ni].first;
        //  we check if the edge is ok to be included in the MST
        //  if a and b are in different trees (if they are on the same we will create a cycle)
        if( find(a) != find(b) ) {
            //  we unite the two trees the edge connects
            unite(a,b);
            //  we add the weight of the edge
            mst_weight += w;
            //  we print the edge and count it
            cout<<a<<" "<<b<<" "<<w<<endl;
            mst_edges++;
        }
        //  increase the index of the edge we will be chacking
        mst_ni++;
    }
    //  Presenting the WEIGHT
    cout<<"\nWeight of the MST is "<<mst_weight<<endl;
    //  THE END
}
 
/*  The example's input:
7 9
1 2 4
7 2 2
6 2 3
6 5 1
5 3 20
4 3 6
1 4 7
2 5 2
2 3 1
 
Explanation of Input:
N M
1      
..  { The edges described as a b w -> meaning (edge from a to b with weight w)
M
*/
 
 
 
/*  The example's output:
2 3 1
6 5 1
2 5 2
7 2 2
1 2 4
4 3 6
 
Weight of the MST is 16
*/
