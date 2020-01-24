#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fathers[100];

int find(int x)
{
	
    if(fathers[x] == x){
        return x;
    }
    return find(fathers[x]);
}
void union(int x, int y)
{
  int fx = find(x);
    int fy = find(y);
    fathers[fx] = fy;
}


int main()
{
	for(int i=0;i<100;i++)
	{
		fathers[i]=i;
	}
	int n,m,a,b,w;
    vector < pair < int, pair <int,int > > > edges;
    cout<<"enter value of m- no of vertex \n";
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	cout<<"enter value of weight,x coordinate, y coordinate \n";
    	cin>>w>>a>>b;
    	edges.push_back(make_pair( w,make_pair(a,b) ) );
	}
	
	cout<<endl;
    int mst_weight = 0, mst_edges = 0;
    int mst_ni = 0;
    sort(edges.begin(),edges.end());
    while( (mst_ni < m) ){
        a = edges[mst_ni].second.first;
        b = edges[mst_ni].second.second;
        w = edges[mst_ni].first;
        if( find(a) != find(b) ) {
            union(a,b);
            mst_weight += w;
            cout<<a<<" "<<b<<" "<<w<<endl;
            mst_edges++;
        }
        mst_ni++;
    }
    cout<<"\nWeight of the MST is "<<mst_weight<<endl;
	
}
