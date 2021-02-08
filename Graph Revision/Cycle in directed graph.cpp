#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF INT_MAX
const long long MOD = 1e9+7;


//PASTE Requirements

//vector<bool> visited(50, false);

vector<int> graph[50];


bool dfs(int source, bool visited[], bool recStack[])
{
	if(!visited[source])
	{
		visited[source] = true;
		recStack[source] = true; 

		for(auto it : graph[source])
		{
			if(!visited[it] && dfs(it, visited, recStack))
			{
				return true;
			}
			else if(recStack[it])
			{
				return true;
			}
		}
	}

	recStack[source] = false;
	return false;
}


//---------------------SOLUTION--------------------\\


void solve()
{
	int n,e;
	cin>>n>>e;

	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		
		//graph[v].push_back(u);
	}

	bool visited[50];
	bool recStack[50];

	for(int i=0; i<50; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	for(int i=1; i<=n; i++)
	{
		
		if(!visited[i])
		{
			if(dfs(i,visited,recStack))
			{
				cout<<"CYCLE"<<endl;
				return;
			}
		}
	}
	cout<<"NO CYCLE";
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

/*
Input
7 8
2 3
1 2
5 1
4 1
5 4
4 6
6 7
7 5
output: Cycle

Input
6 5
1 2
5 2
6 5
2 3
4 3

Output: No Cycle
*/
