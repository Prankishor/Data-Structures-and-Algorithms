//Dynamic Programming
// Unbounded Knapsack Problem 
//Same as Knapsack, only difference is we can take an item multiple times, so return (n) if the item is taken else return for (n-1) -> remember icecream example ? 

#include<bits/stdc++.h>
using namespace std;


int dp[4][101];

int knapsackTab(int n, int weight[], int profit[], int bag)
{
	
	//initialize (Step 1)
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<bag+1; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
		}
	}
	
	//Step 2 , conditons are same as recursive code. (Change n (No. of items) with i and bag (weight of knapsack)  with j, and insert it into a loop
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<bag+1; j++)
		{
			if(weight[i-1]<=j) // Same condition as in recursion
			{
				//We are just replacing n with i and bag with j
				dp[i][j]=max(profit[i-1]+dp[i][j-weight[i-1]], dp[i-1][j]);
			}
			else
			{
				dp[i][j] =dp[i-1][j];
			}
		}
	}
	return dp[n][bag];
	
}

int main()
{
	//n = no. of items
	int n = 3;
	//weight of items
	int weight[n] = {5, 10, 15};
	//profit of items
	int profit[n] = {10, 30, 20};
	//capacity of our bag (knapsack)
	int bag = 100;
	
	//This line is for solution 2. memset initializes all the values to of a array to given value (-1 in this case)
	memset(dp, -1, sizeof(dp));
	
	int maxProfit = knapsackTab(n, weight, profit, bag);
	cout<<maxProfit<<endl;
}
