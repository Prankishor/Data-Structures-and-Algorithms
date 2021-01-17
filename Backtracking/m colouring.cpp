#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define V 4

//USE ll NOT int

bool isSafe(int v, int c, bool graph[][V], int color[])
{
	for(int i=0; i<V; i++)
	{
		if(graph[v][i]==1 && color[i]==c)
		{
			return false;
			
		}
	}
	return true;

}

bool graphColoringUtil(int color[], bool graph[][V], int m, int v)
{
	if(v==V)
	{
		return true;
	}

	for(int c=1; c<=m; c++)
	{
		if(isSafe(v, c, graph, color))
		{
			color[v]=c;
		

		if(graphColoringUtil(color, graph, m, v+1))
		{
			return true;
		}

		color[v]=0;

	}
}
	return false;

}

void graphColoring(bool graph[][V], int m)
{
	int color[V];

	for(int i=0; i<V; i++)
	{
		color[i]=0;
	}

	if(graphColoringUtil(color, graph, m, 0)==false)
	{
		cout<<"No soloution"<<endl;
		return;
	}
	for(int i=0; i<V; i++)
	{
		cout<<color[i]<<" ";
	}
	return;
	
}

int main()
{
	
    /* Create following graph and test 
       whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}



