#include<bits/stdc++.h>
using namespace std;


int MAH(int a[], int n)
{
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
    return mx;
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>a[i][j];
		}
	}
	
	int b[m];
	for(int i=0; i<m; i++)
	{
		b[i]=a[0][i];
	}
	
	int mx = MAH(b, m);
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i][j]==0)
			{
				b[j]=0;
			}
			else
			{
				b[j] = b[j]+a[i][j];
			}
		}
	
		mx = max(mx, MAH(b, m));
	}
	cout<<mx<<endl;
	
}
