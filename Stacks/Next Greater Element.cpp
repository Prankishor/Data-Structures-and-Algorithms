#include<bits/stdc++.h>
using namespace std;


//Wrote by my own after viewing the logic, was very close, couldn't pass all test cases in gfg
//Refer : Aditya Verma Youtube video

//changes after watching the full video is reflected
int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	stack<int> s;
	vector<int> v;
	
	/*for(int i=n-1; i>=0; i--)
	{
		if(s.empty())
		{
			v.push_back(-1);
			//s.push(a[i]);
		}
		else if(s.size()>0 && s.top()>a[i])
		{
			while(!s.empty() && s.top() <= a[i] )
			{
				s.pop();
			}
			if(s.empty())
			{
				v.push_back(-1);
				//s.push(a[i]);
			}
			else
			{
				v.push_back(s.top());
				//s.push(a[i]);
			}
		}
		s.push(a[i]);
	}*/
	
	for(int i=n-1; i>=0; i--)
	{
		if(s.size()==0)
		{
			v.push_back(-1);
		}
		else if(s.size()>0 && s.top()>a[i])
		{
			v.push_back(s.top());
		}
		else if(s.size()>0 && s.top()<=a[i])
		{
			while(s.size()>0 && s.top()<=a[i])
			{
				s.pop();
			}
			if(s.size()==0)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(s.top());
			}
		}
		s.push(a[i]);
	}
	
	reverse(v.begin(), v.end());
	for(int i=0; i<n; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
