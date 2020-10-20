#include<bits/stdc++.h>
using namespace std;

//Just find the NEXT GREATER to Left and store its index in the vector. Do this with the help of Stack (Next Greater Element to Left) 
//After this, traverse the given array and subtract the index with the corresponding value in vector, it gives the answer. How? Socho, karke dekho

int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	stack<pair <int, int> > s;
	vector<int> v;
	
	for(int i=0; i<n; i++)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top().first>a[i])
		{
			
			v.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first<=a[i])
		{
			while(s.size()>0 && s.top().first<=a[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top().second);
			}
		}
		s.push({a[i], i});
	}
	
	
	for(int i=0; i<n; i++)
	{
		v[i]= abs(i-v[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
