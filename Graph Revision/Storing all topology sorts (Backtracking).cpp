#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF INT_MAX
const long long MOD = 1e9+7;


//PASTE Requirements

vector<bool> visited(50, false);
vector<int> graph[50];
vector<int> indegree(50, 0);
vector<vector<int>> ans;





//---------------------SOLUTION--------------------\\
//All TOPO ALGORITHM (Backtracking)

void allTopologySort(int n, vector<int> &res)
{
	bool flag = false;

	for(int i=1; i<=n; i++)
	{
		if(visited[i]==false && indegree[i]==0)
		{
			for(auto it : graph[i])
			{
				indegree[it]--;
			}

			res.push_back(i);
			visited[i]=true;
			allTopologySort(n, res);

			//Backtrack

			visited[i]=false;
			res.erase(res.end()-1);

			for(auto it : graph[i])
			{
				indegree[it]++;
			}
			flag = true;

		}
	}

	if(!flag)
	{
		ans.push_back(res);
	}
}

void solve()
{
	int n,e;
	cin>>n>>e;

	for(int i=0; i<e; i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]++;
		//graph[v].push_back(u);
	}
	vector<int> res;
	allTopologySort(n, res);

	sort(ans.begin(), ans.end());

	for(auto i: ans[0])
	{
		cout<<i<<" ";
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

