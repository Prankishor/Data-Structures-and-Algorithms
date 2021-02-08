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

	 for(int i=0; i<n; i++)
	 {
	 	cout<<i;
	 	for(int j=0; j<graph[i].size(); j++)
	 	{
	 		cout<<"->"<<graph[i][j];
	 	}
	 	cout<<endl;
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
0->1->4
1->0->4->3->2
2->1->3
3->1->2->4
4->0->1->3

*/

