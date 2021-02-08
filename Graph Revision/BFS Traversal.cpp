#include<bits/stdc++.h>
using namespace std;
#define int long long 

//Adjacency List for Grpah representation

int32_t main()
{
	 int n,e;
	 cin>>n>>e;

	 vector<int> graph[n];

	 for(int i=0; i<e; i++)
	 {
	 	int u, v;
	 	cin>>u>>v;

	 	graph[u].push_back(v);
	 	graph[v].push_back(u);
	 }

	 //Breadth First Search

	 bool visited[n] = {false};

	 queue<int> q;
	 q.push(0);
	 visited[0]=true;

	 

	 while(!q.empty())
	 {
	 	int node = q.front();
	 	q.pop();
	 	cout<<node<<" ";

	 	for(auto it: graph[node])
	 	{
	 		if(!visited[it])
	 		{
	 			visited[it]=true;
	 			q.push(it);
	 		}
	 	}
	 }
 /*
Sample input: 

5 7
0 1 
0 4
1 4
1 3
1 2
2 3
4 3

Output: 
0 1 4 3 2
*/
