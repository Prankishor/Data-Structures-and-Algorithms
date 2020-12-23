#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	void dfsUtil(int s, bool visited[]);
	public:
		Graph(int v);
		void addEdge(int v1, int v2);
		void dfs(int s);
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}


void Graph::dfsUtil(int s, bool visited[])
{
	visited[s]=true;
	
	cout<<s<<" ";
	
	list<int>::iterator i;
	for(i=adj[s].begin(); i!=adj[s].end(); ++i)
	{
		if(!visited[*i])
		{
			dfsUtil(*i, visited);
		}
	}
}
void Graph::dfs(int s)
{
	bool *visited = new bool[v];
	
	for(int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	
	dfsUtil(s, visited);
	
}


int main()
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.dfs(2); 
  
    return 0; 
}
