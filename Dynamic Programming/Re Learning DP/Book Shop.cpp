#include<bits/stdc++.h>
using namespace std;

#define ll        long long 
#define pb        push_back
#define mem1(a)   memset(a, -1, sizeof(a))
#define mem0(a)	  memset(a, 0, sizeof(a))

const long long MOD = 1e9+7;
const long long INF = 1e18;


//PASTE Requirements

int dp[1001][100001];

//---------------------SOLUTION--------------------\\

int books(int h[], int s[], int x, int n)
{

	for(int i=0; i<n+1; i++){
		for(int j=0; j<x+1; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
		}
	}


	for(int i=1; i<n+1; i++){
		for(int j=1; j<x+1; j++){
			if(h[i-1]<=j){
				dp[i][j] = max(s[i-1]+dp[i-1][j-h[i-1]], dp[i-1][j]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][x];
}

void solve()
{
	
	int n, x;
	cin>>n>>x;

	int h[n], s[n];

	for(int i=0; i<n; i++)
	{
		cin>>h[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>s[i];
	}

	cout<<books(h, s, x, n);
}
//--------------------------------------------------\\

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


