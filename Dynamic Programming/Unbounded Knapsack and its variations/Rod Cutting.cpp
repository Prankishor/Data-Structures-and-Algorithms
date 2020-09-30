//Dynamic Programming
// ROD CUTTING PROBLEM (SAME AS UNBOUNDED KNAPSACK)
//I have copy pasted the unbounded knapsack code because it is the same. The only take away is, lenghts are not given only one length
//is given that is the length of the rod. So it is obvious we need to make an array with values from 1 to given length. Thats it, baki 
//diya hua hai sab. See driver code, you will undrstand

#include<bits/stdc++.h>
using namespace std;




int knapsackTab(int n, int weight[], int profit[], int bag)
{
	int dp[n+1][bag+1];
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

	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<bag+1; j++)
		{
			if(weight[i-1]<=j) 
			{
				//We are just replacing i-1 with i in dp[i][j-weigh....]
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
	//n = size of rod
	int n;
	cin>>n;
	int profit[n]; //it is given
	int rod[n];
	for(int i=0; i<n; i++)
	{
		cin>>profit[i];
	}
	for(int i=0; i<n; i++) //making this own
	{
		rod[i]=i+1;
	}
	
	int maxProfit = knapsackTab(n, rod, profit, n);
	cout<<maxProfit<<endl;
}
