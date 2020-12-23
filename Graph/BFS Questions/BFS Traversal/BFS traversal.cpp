#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	public:
		Graph(int v);
		void addEdge(int v1, int v2);
		void bfs(int src);
		
		
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


void Graph::bfs(int src)
{
	queue<int> q;
	
	bool *visited = new bool[v];
	
	for(int i=0; i<v; i++)
	{
		visited[i] = false;
	}
	
	q.push(src);
	visited[src] = true;
	list<int>::iterator i;
	
	while(!q.empty())
	{
		int s = q.front();
		cout<<s<<" ";
		q.pop();
		
		
		for(i=adj[s].begin(); i!=adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				q.push(*i);
				visited[*i]=true;
			}
			
			
		}
	}
	
	
}

int main()
{
	Graph g(5);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	
	g.bfs(0);
	
	return 0;
	
	
	
	
}
