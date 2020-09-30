//Dynamic Programming
//Variation of Coin Change (Unbounded Knapsack) : Coin Change(min)
//Here, when making the dp table, if we are not given any coin and we want sum 0, we will keep searching for coins till infinity.
//So initialize with INT_MAX-1 (-1 to avoid overflow) in the first row and with 0 , the first column, (first box remains INTMAX))


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
		dp[i][0]=0;
	}

	for(int i=0; i<sum+1; i++)
	{
		dp[0][i]=INT_MAX-1;
	}
	
	for(int j=1; j<sum+1; j++)
	{
		if((j/a[1])%2==0)
		{
		dp[1][j] = j/a[1];
	    }
	    else
	    {
	    	dp[1][j]=INT_MAX-1;
		}
	}
	

	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(a[i-1]<=j)
			{
			    //HERE IS THE CHANGE
				dp[i][j] = min(1+ dp[i][j-a[i-1]] , dp[i-1][j]);
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
	int t;
	cin>>t;
	while(t--)
	{
		int sum, n; //sum = total money needed, n = number of coins
		cin>>sum>>n;
		
		int a[n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		
		cout<<countSubset(n, a, sum)<<endl;
	}
}
