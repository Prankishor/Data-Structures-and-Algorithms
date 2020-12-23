#include<bits/stdc++.h>
using namespace std;


class Graph{
	int v;
	list<int>*adj;
	
	void DFSRec(int v, bool visited[]);
	
	public:
		Graph(int v); 
		
		void addEdge(int v1, int v2);
		
		void DFS(int s);
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}

void Graph::DFSRec(int v, bool visited[])
{
	visited[v] = true;
	cout<<v<<" ";
	
	list<int>::iterator it;
	for(it=adj[v].begin(); it!=adj[v].end(); it++){
		if(!visited[*it])
		{
			DFSRec(*it, visited);
		}
	}
}

void Graph::DFS(int s)
{
	bool *visited = new bool[v];
	
	for(int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	
	DFSRec(s, visited);
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 0);
	g.addEdge(3, 3);
	
	g.DFS(2);
	
	
}
