#include<bits/stdc++.h>
using namespace std;
#define V 9

int minDistance(int dist[V], bool sptSet[V])
{
	int min = INT_MAX, minIndex;
	
	for(int i=0; i<V; i++)
	{
		if(dist[i]<min && sptSet[i]==false)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void printdist(int dist[V])
{
	for(int i=0; i<V; i++)
	{
		cout<<i<<" "<<" "<<dist[i]<<endl;
	}
}
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
	
	for(int i=0; i<V; i++)
	{
		dist[i]=INT_MAX, sptSet[i]=false;
	}
	
	dist[src]=0;
	
	for(int i=0; i<V-1; i++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u]=true;
		
		for(int v=0; v<V; v++)
		{
			if(sptSet[v]==false && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<=dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	
	printdist(dist);
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
