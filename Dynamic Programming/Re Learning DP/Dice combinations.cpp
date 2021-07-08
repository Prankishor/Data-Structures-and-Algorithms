#include<bits/stdc++.h>
using namespace std;

#define int       uint64_t
#define pb        push_back
#define mem1(a)   memset(a, -1, sizeof(a))
#define mem0(a)	  memset(a, 0, sizeof(a))

const long long MOD = 1e9+7;
const long long INF = 1e18;


//PASTE Requirements



//---------------------SOLUTION--------------------\\



void solve()
{
	//DICE COMBINATIONS: My observation as a beginner in DP
	//1. Finding intuition is very necessary
	//2. Observe, to find no. of ways for lets say to get a sum of 3,
	//we need no. of ways to get sum 2? Yes, after that, i.e after finding sum 
	//of 2 , we need a '1' to make it 3, so can we say we need to find number of ways
	// to find 2 + no. of ways to find 1 = total will be no of ways to find 3.
	//that is what we exactly will do. So how to implement this? Starting from
	//bottom, base case? what is base case? finding a sum of 0? In how many
	//ways can we do that? 1 way. (The empty set i.e by doing nothing). 
	//After that, are there any edge cases? Yes, what if our dice gives a 6, and 
	//we just need a sum of 3. We can ignore such cases. 

	int n;
	cin>>n;

	vector<int> dp(n+1, 0);
	dp[0] = 1;

	for(int sum=1; sum<n+1; sum++)
	{
		for(int dice = 1; dice<=6; dice++)
		{
			if(dice>sum)
			{
				break;
			}

			dp[sum] = (dp[sum]+dp[sum-dice])%MOD;
		}
	}

	cout<<dp[n]<<endl;
}	

//--------------------------------------------------\\

signed main()
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


