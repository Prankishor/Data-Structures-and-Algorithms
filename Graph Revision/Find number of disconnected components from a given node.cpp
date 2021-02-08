#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF INT_MAX
const long long MOD = 1e9+7;


//PASTE Requirements


//---------------------SOLUTION--------------------\\

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
		graph[v].push_back(u);
	}

	int x;
	cin>>x;

	bool visited[n+1] = {false};
	stack<int> s;
	s.push(x);
	visited[x]=true;

	while(!s.empty())
	{
		int u = s.top();
		s.pop();

		for(int i=0; i<graph[u].size(); i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=true;
				s.push(graph[u][i]);
			}
		}
	}

	int count = 0;
	for(int i=0; i<n+1; i++)
	{
		if(visited[i]==true)
		{
			count++;
		}
	}

	cout<<n-count<<endl;

	

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

