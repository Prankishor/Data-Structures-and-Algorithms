#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    unordered_map<int, int> um;
	    
	   

	    priority_queue<pi> pq;
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	        um[a[i]]++;
	        
	    }
	    for(auto i:um)
	    {
	        pq.push(make_pair(i.second, i.first));
	        
	    }
	    
	    while(pq.size()>0)
	    {
	       int value = pq.top().second;
	       int freq = pq.top().first;
	       
	       for(int i=freq; i>0; i--)
	       {
	           cout<<value<<" ";
	       }
	       pq.pop();
	    }
	    cout<<endl;
	}
}
