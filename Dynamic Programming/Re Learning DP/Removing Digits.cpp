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
	ll n;
	cin>>n;

	ll dp[n+1];
	dp[0]=0;

	for(ll i=1; i<=n; i++){
		
		ll minSteps = INF;
		ll temp = i;

		while(temp!=0){
			ll digit = temp%10;
			temp = temp/10;

			if(digit == 0)
			{
				continue;
			}

			minSteps = min(minSteps, 1+dp[i-digit]);
		}

		dp[i] = minSteps;
	}

	cout<<dp[n];
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


