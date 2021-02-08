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

	bool visited[n] = {false};
	bool ok = false;

	stack<int> s;
	s.push(0);
	visited[0]=true;
	int parent = -1;

	while(!s.empty())
	{
		int u=s.top();
		s.pop();

		for(int i=0; i<graph[u].size(); i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=true;
				parent = u;
				s.push(graph[u][i]);
			}
			else
			{
				if(graph[u][i]!=parent)
				{
					ok = true;
					break;
				}
			}
		}
		if(ok)
		{
			break;
		}
	}

	if(ok)
	{
		cout<<"Cycle Detected";
	}
	else
	{
		cout<<"No Cycle";
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

