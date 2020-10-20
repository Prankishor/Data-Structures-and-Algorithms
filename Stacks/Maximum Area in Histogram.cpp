#include<bits/stdc++.h>
using namespace std;

//make a vector for all NSR 
//make a vector for all NSL

//subtract them to get width
int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	stack<pair<int, int> > s;
	vector<int> nsr;
	vector<int> nsl;
	
	
	//Next smallest to right
	for(int i=n-1; i>=0; i--)
	{
		if(s.size()==0)
		{
			nsr.push_back(n);
		}
		else if(s.size()>0 && s.top().second<a[i])
		{
			nsr.push_back(s.top().first);
		}
		else if(s.size()>0 && s.top().second>=a[i])
		{
			while(s.size()>0 && s.top().second>=a[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				nsr.push_back(n);
			}
			else 
			{
				nsr.push_back(s.top().first);
			}
		}
		s.push({i, a[i]});
	}
	
	reverse(nsr.begin(), nsr.end());

    //next smallest to left
	while(s.size()>0)
	{
		s.pop();
	}
	
	for(int i=0; i<n; i++)
	{
		if(s.size()==0)
		{
			nsl.push_back(-1);
		}
		else if(s.size()>0 && s.top().second<a[i])
		{
			nsl.push_back(s.top().first);
		}
		else if(s.size()>0 && s.top().second>=a[i])
		{ 
			while(s.size()>0 && s.top().second>=a[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				nsl.push_back(-1);
			}
			else 
			{
				nsl.push_back(s.top().first);
			}
		}
		s.push({i, a[i]});
	}
	
	vector<int> w;
	
	//storing nsr-nsl-1
	for(int i=0; i<n; i++)
	{
		w.push_back(abs(nsr[i]-nsl[i])-1);
	}
	
	int mx = INT_MIN;
	for(int i=0; i<n; i++)
	{
		if(a[i]*w[i]>mx)
		{
			mx = a[i]*w[i];
		}
	}
    cout<<mx<<endl;
}
