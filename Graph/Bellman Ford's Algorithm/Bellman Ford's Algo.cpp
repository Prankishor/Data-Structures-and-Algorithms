//Bellman Ford Algorithm
#include<bits/stdc++.h>
using namespace std;

//Create an edge blueprint 
struct Edge{
	int src, dest, weight;
};

//Create a graph blueprint
struct Graph{
	int V, E;
	Edge *edge;
};


//Make a funtion to make graph
struct Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

//Algorithm
void BellmanFord(Graph *graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dis[V];
	for(int i=0; i<V; i++)
	{
		dis[i]=INT_MAX;
	}
	dis[src]=0;
	
	for(int i=1; i<=V-1; i++)
	{
		for(int j=0; j<E; j++)
		{
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dis[u]!=INT_MAX && dis[u] + weight<dis[v])
			{
				dis[v] = dis[u] + weight;
			}
		}
	}
	
		for(int j=0; j<E; j++)
		{
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dis[u]!=INT_MAX && dis[u] + weight<dis[v])
			{
				cout<<"Graph contains negative cycle in "<<v<<endl;
			}
		}
		
		for(int i=0; i<V; i++)
		{
			cout<<i<<"->"<<"distance: "<<dis[i]<<endl;
		}
	
	
}
int main()
{
	int V = 8;
	int E = 10;
	Graph *graph = createGraph(V, E);
	
	/*graph->edge[0].src = 0;
	graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
   
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
   
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
   
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  

    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
   
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
  
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; */
    
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = 1;
    
    graph->edge[1].src = 1; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 1;
    
    graph->edge[2].src = 2; 
    graph->edge[2].dest = 4; 
    graph->edge[2].weight = 1;
    
    graph->edge[3].src = 4; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = -3;
    
    graph->edge[4].src = 3; 
    graph->edge[4].dest = 2; 
    graph->edge[4].weight = 1;
    
    graph->edge[5].src = 1; 
    graph->edge[5].dest = 5; 
    graph->edge[5].weight = 4;
    
    graph->edge[6].src = 1; 
    graph->edge[6].dest = 6; 
    graph->edge[6].weight = 4;
    
    graph->edge[7].src = 5; 
    graph->edge[7].dest = 6; 
    graph->edge[7].weight = 5;
    
    graph->edge[8].src = 6; 
    graph->edge[8].dest = 7; 
    graph->edge[8].weight = 4;
    
    graph->edge[9].src = 5; 
    graph->edge[9].dest = 7; 
    graph->edge[9].weight = 3;
    
    
    
    
    /*matrix[0][1] = 1;
    matrix[1][2] = 1;
    matrix[2][4] = 1;
    matrix[4][3] = -3;
    matrix[3][2] = 1;
    matrix[1][5] = 4;
    matrix[1][6] = 4;
    matrix[5][6] = 5;
    matrix[6][7] = 4;
    matrix[5][7] = 3;*/
    
    BellmanFord(graph, 0);
}
