#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
	int source;
	int destination;
	int weight;
};

bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

int find(int v, int *parent)
{
	if(parent[v] == v)
	{
		return v;
	}
	return find(parent[v], parent);
}
void kruskals(Edge *edges, int n, int e)
{
	sort(edges, edges+e, compare);
	
	Edge *output = new Edge[n-1];
	
	int *parent = new int[n];
	
	for(int i=0; i<n; i++)
	{
		parent[i]=i;
	}
	
	int count = 0; //to count no of edges added in mst
	int i = 0; //current edge
	
	while(count != n-1)
	{
		Edge currentEdge = edges[i];
		
		//check if we can add this currentEdge in mst
		
		int sourceParent = find(currentEdge.source, parent);
		int destinationParent = find(currentEdge.destination, parent);
		
		if(sourceParent != destinationParent)
		{
			output[count] = currentEdge;
			count++;
			
			parent[sourceParent] = destinationParent;		}
		i++;
		
	}
	
	for(int i=0; i<n-1; ++i)
	{
		if(output[i].source < output[i].destination)
		{
		
		cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
	}
	
	else
	{
		cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
	}
	}
}


int main()
{
	int n,e;
	cin>>n>>e;
	
	Edge *edges = new Edge[e];
	
	for(int i=0; i<e; ++i)
	{
		int s, d, w;
		cin>>s>>d>>w;
		
		edges[i].source = s;
		edges[i].destination = d;
		edges[i].weight = w;
	}
	
	kruskals(edges, n, e);
}
