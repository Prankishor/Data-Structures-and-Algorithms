#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const long long MOD = 1e9+7;

//PASTE Requirements


//---------------------SOLUTION--------------------\\


void solve()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	//1
	int x = 1;

	//first element of array
	int y = a[0];

	for(int i=1; i<n; i++)
	{
		y=y^a[i];
	}

	for(int i=2; i<=n+1; i++)
	{
		x=x^i;
	}

	int ans = x^y;
	cout<<ans<<endl;



	
}

//--------------------------------------------------\\

int32_t main()
{
	solve();	
}

