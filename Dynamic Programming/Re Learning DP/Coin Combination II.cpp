#include<bits/stdc++.h>
using namespace std;

#define ll        long long 
#define pb        push_back
#define mem1(a)   memset(a, -1, sizeof(a))
#define mem0(a)	  memset(a, 0, sizeof(a))

const long long MOD = 1e9+7;
const long long INF = 1e18;


//PASTE Requirements



//---------------------SOLUTION--------------------\\



void solve()
{
	int n, sum;
	cin>>n>>sum;

	int coins[n+1];
	for(int i=1; i<n+1; i++)
	{
		cin>>coins[i];
	}

	//dp[coins][money]
	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

	//dp[0][0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j==0)
			{
				dp[i][j] = 1; //1 way when sum = 0
			}
			else{
				//take ith coin
				int op1 = (coins[i] > j) ? 0 : dp[i][j-coins[i]];
				//dont take ith coin
				int op2 =(i==1) ? 0 : dp[i-1][j];

				dp[i][j] = (op1+op2)%MOD;
			}
		}
	}
	cout<<dp[n][sum];

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


