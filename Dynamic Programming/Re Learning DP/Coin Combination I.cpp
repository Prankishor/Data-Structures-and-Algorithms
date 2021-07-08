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
	int n,money;
	cin>>n>>money;
	int coins[n];

	for(int i=0; i<n; i++)
	{
		cin>>coins[i];
	}

	vector<int> dp(money+1, 0);
	dp[0]=1;

	for(int sum=1; sum<=money; sum++)
	{
		for(int coin = 0; coin<n; coin++)
		{
			if(sum-coins[coin]>=0)
			{
				dp[sum] = (dp[sum]+dp[sum-coins[coin]])%MOD;
			}
			
		}
	}
	cout<<dp[money];

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


