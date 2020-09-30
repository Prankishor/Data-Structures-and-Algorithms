//Dynamic Programming 
//Practice Problem 4
//Variant of Knapsack -> Count Subset Sum
//Problem: Given an array and a number k, return the number of subsets possible whose sum would be equal to k.
//Method: Tabulation

#include<bits/stdc++.h>
using namespace std;

int countSubset(int n, int a[], int sum)
{
	int dp[n+1][sum+1];
	
	//Initialization, same as subset sum (instead of T->1, instead of F->0)
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
			if(a[i-1]<=sum)
			{
				//Here since return type is not boolean anymore, we will not use || (or) instead we will add up the
				//results
				dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
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
	int a[6] = {2,3,5,6,8,10};
	int sum = 10;
	int ans = countSubset(6, a, sum);
	cout<<ans<<endl;
}
