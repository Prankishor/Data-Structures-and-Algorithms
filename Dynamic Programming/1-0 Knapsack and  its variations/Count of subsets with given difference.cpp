//Dynamic Programming
//Problem 6: Count subsets with given difference 
//Explanation: Count the number of subets whose differene is equal to the given difference
//Concept: We know :
//S1 - S2 = given diff->(1)
//S1 + S2 = sum of array->(2)
//Equation (1) + (2) gives us:
//S1 = (given diff + sum of array)/2

//So now we know what sum of S1 should be. So count the number of subsets that would give us sum of S1


int countSubsetSum(int a[], int n, int sum)
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

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 4;
	int a[n] = {1, 2, 3, 3};
	int x = 6;
	
	int sumOfArray = 0;
	for(int i=0; i<n; i++)
	{
		sumOfArray+=a[i];
	}
	int sum = (x+sumOfArray)/2;
	cout<<countSubsetSum(a, n, sum);
}
