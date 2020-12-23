#include<iostream>
using namespace std;

int dfs(int c,int x,int y,int k, vector<bool> &visited[], vector<int> graph[])
{
    visited[x]=true;
    c++;
    
    if(c==2)
    {
        if(x==y)
        {
            return 1;
        }
    }
    vector<int>::iterator i;
    for(i=graph[x].begin(); i!=graph[x].end(); ++i)
    {
        if(!visited[*i])
        {
            dfs(c,x, y, k, visited, graph);
        }
        
    }
}


int main()
 {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int N,x,y,k;
	    cin>>N;
	    
	    vector<int> graph[N];
	    
	    for(int i=0; i<N*2; ++i)
	    {
	        cin>>x>>y;
	        graph[x].push_back(y);
	    }
	    cin>>x>>y>>k;
	    
	    
	    vector<bool> visited(N+1, false);
	    int paths = 0;
	    int c=-1;
	    
	    paths+= dfs(c,x,y,k,visited, graph);
	    
	    cout<<paths<<endl;
	
	}
	return 0;
}
