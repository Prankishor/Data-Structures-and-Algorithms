//Author PRANKISHOR ;)

#include<bits/stdc++.h>

using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	public:
		Graph(int v);
		void add_edge(int v1, int v2);
		void bfs_sp(int s, int d);
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<int>[v];
}

void Graph::add_edge(int v1, int v2)
{
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}

void Graph::bfs_sp(int s, int d)
{
	queue<int> q;
	vector<int> dist(v, INT_MAX);
	bool *visited = new bool[v];
	vector<int> pred(v, -1);
	
	q.push(s);
	visited[s]=true;
	dist[s]=0;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		list<int>::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
		{
			if(!visited[*i])
			{
			dist[*i]=dist[u]+1;
			q.push(*i);
			visited[*i]=true;
			pred[*i]=u; //print koribo paro incase path tu lage
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
	int s = 0;
	int d = 7;
	Graph g(8);
	
	g.add_edge(0, 1); 
    g.add_edge(0, 3); 
    g.add_edge(1, 2); 
    g.add_edge(3, 4); 
    g.add_edge(3, 7); 
    g.add_edge(4, 5); 
    g.add_edge(4, 6); 
    g.add_edge(4, 7); 
    g.add_edge(5, 6); 
    g.add_edge(6, 7); 
    
    g.bfs_sp(s, d);
    
    
}
