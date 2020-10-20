#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	int temp;
	priority_queue<int, vector<int>, greater<int> >pq;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		pq.push(temp);
	}
	int cost = 0;
	temp = 0;
	while(pq.size()>=2)
	{
		temp+= pq.top();
		pq.pop();
		temp+= pq.top();
		pq.pop();
		
		cost+=temp;
		pq.push(temp);
		temp = 0;
	}
	cout<<cost<<endl;
	
}
