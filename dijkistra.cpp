#include<iostream>
#include <bits/stdc++.h>
int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < 9; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}  
dijkistra(int graph[9][9], int src)
{
	int dist[5];
	bool sptset[50];
 for (int i = 0; i < 9; i++) 
        dist[i] = INT_MAX, sptset[i] = false; 
  
    dist[src] = 0; 
  
	for(int c=0;c<9;c++)
	{
	int u=minDistance(dist, sptset);
	sptset[u]=true;
	for(int v=0;v<9;v++)
	{
			if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
		}	
		
		
	}
	 printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < 9; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
	
	
	
}
int main()
{
	int graph[9][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
	dijkistra(graph,0);
}
