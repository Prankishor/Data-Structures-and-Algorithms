#include<bits/stdc++.h>
using namespace std;

int targetSum(int a[], int n, int sum)
{
	int dp[n+1][sum+1];
	
	for(int i=0; i<sum+1; i++)
	{
		dp[0][i]=0;
	}
	for(int i=0; i<n+1; i++)
	{
		dp[i][0]=1;
	}
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(dp[i-1][j]<=j)
			{
				dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main()
{
	int n = 1;
	int a[n] = {1};
	int x = 2;
	
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
	}
	sum=(x+sum)/2;
	
	cout<<targetSum(a, n, sum);
}
