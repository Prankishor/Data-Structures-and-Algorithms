#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const long long MOD = 1e9+7;

//PASTE Requirements


//---------------------SOLUTION--------------------\\

void solve()
{
	int n;
	cin>>n;
	vector<int> graph[n+1];

	for(int i=0; i<n-1; i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int x;
	cin>>x;

	int levels[n+1];

	queue<int> q;
	q.push(1);
	bool visited[n+1] = {false};
	levels[1] = 1;
	visited[1]=true;

	while(!q.empty())
	{
		int a = q.front();
		q.pop();

		for(int i=0; i<graph[a].size(); i++)
		{
			if(visited[graph[a][i]]==false)
			{
				q.push(graph[a][i]);
				levels[graph[a][i]] = levels[a]+1;
				visited[graph[a][i]]=true;
			}
		}

	}
	int count = 0;

	for(int i=1; i<n+1; i++)
	{
		if(levels[i]==x)
		{
			count++;
		}
	}

	cout<<count<<endl;

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

