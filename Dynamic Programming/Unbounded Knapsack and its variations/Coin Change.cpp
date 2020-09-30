//Dynamic Programming
//Problem: Coin Change (Max num of ways)
//Variation of Unbounded Knapsack
//Same as COUNT OF SUBSET SUM PROBLEM, just change the necessary to make it unbounded.
//I have copied the count subset sum code

#include<bits/stdc++.h>
using namespace std;

int countSubset(int n, int a[], int sum)
{
	int dp[n+1][sum+1];
	
	for(int i=0; i<n+1; i++)
	{
		dp[i][0]=1;
	}

	for(int i=0; i<sum+1; i++)
	{
		dp[0][i]=0;
	}
	

	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(a[i-1]<=j)
			{
			    //HERE IS THE CHANGE
				dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
			}
			else
			{
				dp[i][j]= dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

int main()
{
	int n=2;
	int a[n] = {1, 2};
	int sum = 5;
	int ans = countSubset(n, a, sum);
	cout<<ans<<endl;
}
