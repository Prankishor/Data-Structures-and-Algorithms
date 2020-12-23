#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	public:
		Graph(int v);
		void addEdge(int v1, int v2);
		void topologicalSort();
	
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}

void Graph::topologicalSort()
{
	//indegree
	vector<int> indegree(v, 0);
	
	for(int u=0; u<v; u++)
	{
		list<int>::iterator i;
		
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
		{
			indegree[*i]++;
		}
		
	}
	
	//queue
	
	queue<int> q;
	
	for(int i=0; i<v; i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	
	//count 
	
	int cnt = 0;
	
	//topo order
	
	vector<int> topo_order;
	
	while(!q.empty())
	{
		int r = q.front();
		topo_order.push_back(r);
		q.pop();
		
		list<int>::iterator i;
		
		for(i=adj[r].begin(); i!=adj[r].end(); i++)
		{
			if(--indegree[*i]==0)
			{
				q.push(*i);
			}
		}
		cnt++;
		
	}	
	
	if(cnt!=v)
	{
		cout<<"THIS GRAPH IS NOT A DAG, HENCE NO TOPOLOGICAL SORTING IS POSSIBLE"<<endl;
	}
	else
	{
		
		for(int i=0; i<v; i++)
		{
			cout<<topo_order[i]<<" ";
		}
		
	}	
	
	
	
	
	
}

int main()
{
	Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5);  
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort(); 
  
    return 0; 
}
