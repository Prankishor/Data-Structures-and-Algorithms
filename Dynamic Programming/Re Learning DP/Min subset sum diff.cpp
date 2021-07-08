#include<bits/stdc++.h>
using namespace std;

#define ll        long long 
#define pb        push_back
const long long MOD = 1e9+7;
const long long INF = 1e18;
#define mem1(a)   memset(a, -1, sizeof(a))
#define mem0(a)	  memset(a, 0, sizeof(a))





//PASTE Requirements


void solve()
{
	int n;
	cin>>n;

	int a[n];
	int sum = 0;

	for(int i=0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
	}

	

	int dp[n+1][sum+1];

	for(int i=0; i<n+1; i++){
		dp[i][0] = 1;
	}

	for(int i=1; i<sum+1; i++){
		dp[0][i] = 0;
	}



	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(a[i-1]<=j){
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}


	int ans = INT_MAX;

	for(int i=0; i<=sum; i++){
		if(dp[n][i]==1){
			ans=min(ans,abs(i-(sum-i)));
		}
	}

	cout<<ans<<endl;

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

