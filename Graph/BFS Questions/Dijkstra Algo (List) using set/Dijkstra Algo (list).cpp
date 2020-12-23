#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list <pair<int, int> > *adj;
	
	public:
		Graph(int v);
		void addEdge(int v1, int v2, int w);
		void shortestPath(int src);
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<pair<int, int> >[v];
}

void Graph::addEdge(int v1, int v2, int w)
{
	adj[v1].push_back(make_pair(v2, w));
	adj[v2].push_back(make_pair(v1, w));
}

void Graph::shortestPath(int src)
{
	vector<int> dist(v+1, INT_MAX);
	
	set <pair<int, int> > setds;
	
	dist[src]=0;
	
	setds.insert(make_pair(0, src));
	
	while(!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		
		int u= tmp.second;
		
		list<pair<int, int> >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			
			if(dist[v]>dist[u]+weight)
			{
				if(dist[v]!=INT_MAX)
				{
					setds.erase(setds.find(make_pair(dist[v], v)));
				}
				
				dist[v]=dist[u]+weight;
				
				setds.insert(make_pair(dist[v],v));
			}
		}
	}
	
	for(int i=0; i<v; i++)
	{
		cout<<i<<" "<<" "<<dist[i]<<endl;
	}
	
	
	
	
}


int main()
{
    int V = 9; 
    Graph g(V); 
  
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0;
}
