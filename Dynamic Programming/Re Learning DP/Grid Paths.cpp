#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
 
 
void solve()
{
	ll n;
	cin>>n;
 
	bool grid[n+1][n+1];
	for(ll i=1; i<n+1; i++){
		for(ll j=1; j<n+1; j++){
			char c;
			cin>>c;
			if(c=='.')
			{
				grid[i][j] = 0;
			}
			else
			{
				grid[i][j]= 1;
			}
		}
	}
 
	ll dp[n+1][n+1];
 
	for(ll i = n; i>=1; i--)
	{
		for(ll j=n; j>=1; j--)
		{
			if(i==n && j==n)
			{
				dp[i][j] = 1;
			}
			else{
				ll op1 = (j==n) ? 0 : dp[i][j+1];
				ll op2 = (i==n) ? 0 : dp[i+1][j];
 
				dp[i][j] = (op1+op2)%mod;
 
				if(grid[i][j]==1){
					dp[i][j] = 0;
				}
			}
 
 
		}
	}
 
	if(grid[n][n]==1){
		cout<<0;
	}
	else{
		cout<<dp[1][1];
	}
 
 
 
}
 
int main()
{
	int t;
	t=1;
	//cin>>t;
 
	while(t--)
	{
		solve();
	}	
	return 0;
}
