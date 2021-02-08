#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF INT_MAX
const long long MOD = 1e9+7;


//PASTE Requirements

//vector<bool> visited;

vector<int> graph[50];

//DFS TOPO ALGORITHM


//---------------------SOLUTION--------------------\\



void solve()
{
	int n,e;
	cin>>n>>e;
	
	vector<int> indegree(n+1, 0);

	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]++;
		//graph[v].push_back(u);
	}

	vector<int> ans;
	queue<int> q;
	int count = 0; //To detect cycle

	for(int i=1; i<=n; i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for( auto i : graph[u] )
		{
			if(indegree[i]!=0)
			{
				indegree[i]--;
			}
			
			if (indegree[i]==0)
			{
				q.push(i);
			}
		}
		ans.push_back(u);
		count++;
	}

	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";
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

