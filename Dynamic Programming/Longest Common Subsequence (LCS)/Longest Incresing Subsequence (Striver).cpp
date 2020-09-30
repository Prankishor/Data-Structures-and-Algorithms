//LONGEST INCREASING SUBSEQUENCE
//BY STRIVER
//Idea is to check previous elements, if they were smaller than the current element, then add their value (lis till that element) to
//the current element

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    //dp array
	    int lis[n];
	    
	    //first element lis will be 1 only.
	    lis[0]=1;
	    
	    //from the second  element to last
	    for(int i=1; i<n; i++)
	    {
	    	//initially lis will be 1
	        lis[i]=1;
	        
	        //if we find someone at the left who is smaller and who have value more than the current element value than update
	        for(int j=0; j<i; j++)
	        {
	            if(a[j]<a[i] && lis[i]<lis[j]+1)
	            {
	                lis[i]=lis[j]+1;
	            }
	        }
	    }
	    cout<<*max_element(lis, lis+n)<<endl;
	}
}
