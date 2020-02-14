

#include <limits.h> 
#include <stdio.h> 
int minDistance(dist, sptset)
{
	
}

void dijkistra(int graph[][], int src)
{
	bool sptset[V];
	int dist[V];
	for(i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[src]=0;
	for(int i=0;i<V-1;i++)
	{
		 int u = minDistance(dist, sptSet);  
        sptset[u] = true; 
        for (int v = 0; v < V; v++) {
		
            if (dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
	}
		printf("Vertex \t\t Distance from Source\n"); 
	    for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
	}
int main() 
{ 
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(graph, 0); 

	return 0; 
} 

