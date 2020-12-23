#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	void topologyUtil(int src, bool visited[], stack<int> &s);
	public:
		Graph(int v);
		void addEdge(int v1, int v2);
		void topology();
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

void Graph::topologyUtil(int src, bool visited[], stack<int> &s)
{
	visited[src]=true;
	
	list<int>::iterator i;
	for(i=adj[src].begin(); i!=adj[src].end(); ++i)
	{
		if(!visited[*i])
		{
			topologyUtil(*i, visited, s);
		}
	}
	
	s.push(src);
}

void Graph::topology()
{
	bool *visited = new bool[v];
	for(int i=0; i<v; i++)
	{
		visited[i]=false;
	}
	stack<int> s;
	
	for(int i=0; i<v; i++)
	{
		if(!visited[i])
		{
			topologyUtil(i, visited, s);
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main()
{
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topology(); 
  
    return 0; 
}

