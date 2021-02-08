#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF INT_MAX
const long long MOD = 1e9+7;


//PASTE Requirements

//    DFS TOPO ALGORITHM


//---------------------SOLUTION--------------------\\

void dfs(int node, bool visited[], stack<int> &s, vector<int> graph[])
{
	visited[node]=true;
	for(int i=0; i<graph[node].size(); i++)
	{
		if(!visited[graph[node][i]])
		{
			dfs(graph[node][i], visited, s, graph);
		}
		
	}
	s.push(node);
}

void solve()
{
	int n,e;
	cin>>n>>e;
	vector<int> graph[n+1];

	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u);
	}

	bool *visited = new bool[n];
	for(int i=0; i<n; i++)
	{
		visited[i]=false;
	}
	stack<int> s;

	for(int i=0; i<n; i++)
	{
		if(!visited[i])
		{
			dfs(i, visited, s, graph);
		}
	}

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}


}

//--------------------------------------------------\\

int main()
{
	/*
	int t;
	cin>>t;

	while(t--)
	{
		solve();
	}
	*/
	solve();	
}

