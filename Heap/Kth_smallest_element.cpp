#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    
	    
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];

	    }
	    int k;
	    cin>>k;
	    priority_queue<int> mq;
	    
	    for(int i=0; i<n; i++)
	    {
	            mq.push(a[i]);
	            if(mq.size()>k)
	            {
	                mq.pop();
	            }
	    }
	    cout<<mq.top()<<endl;
	    
	   
	}
	return 0;
}
