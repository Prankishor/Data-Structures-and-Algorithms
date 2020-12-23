#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
public:
	
	Graph(int v);
	
	void addEdge(int v1, int v2);
	
	void BFS(int s);
};

Graph::Graph(int v)
{
	this->v=v;
	adj= new list<int>[v];
}

void Graph::addEdge(int v1, int v2)
{
	adj[v1].push_back(v2);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[v]; //bool type or array eta bonalu jot visited nodes buror update rakhim
	
	for(int i=0; i<v; i++)
	{
		visited[i]=false; //initially sob false maane unvisited
	}
	
	list<int> queue;  //queue eta bonaisu jot next nodes junbur print hbo laage store kori jaam
	
	visited[s]=true; //s tu source first node, heitu visit dilu, so true kori queue bhoralu
	queue.push_back(s);
	
	list<int>::iterator i;
	
	while(!queue.empty()) //queue jetiya leke elements aase tetiya leke
	{
		s = queue.front(); //s tu ami front tu loi lolu and print korilu, then pop from queue, front tu next element
		//tole gusi jabo, loop solibo, s tu aako nije next element tule assign hoi jabo
		cout<<s<<" ";
		queue.pop_front();
		
		for(i=adj[s].begin(); i!=adj[s].end(); i++) //s eta array element hoi jot list aase. hei list to traverse korim]
		//iterator di, aaru junbur visited nhoi heibur visit korim and queue le push korim.
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
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
	
	g.BFS(0);
	
	
	return 0;	
}
