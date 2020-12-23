#include<bits/stdc++.h>
using namespace std;


void addEdge(vector <int> graph[], int v1, int v2)
{
	graph[v1].push_back(v2);
	graph[v2].push_back(v1);
}

void printGraph(vector <int> graph[], int v)
{
	
	vector<int>::iterator x; 
	for(int i=0; i<v; ++i)
	{
		cout<<i;
		for( x=graph[i].begin(); x!=graph[i].end(); x++)
		{
			cout<<"-> "<<*x;
		}
		
		cout<<endl;
	}
}
int main()
{
	/*int v = 5;
	
	vector <int> graph[v];
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	printGraph(graph, v);
	*/
	
	
	int v = 4;
	
	vector <int> graph[v];
	
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	printGraph(graph, v);
	return 0;
}





