//Inspired by Tarun, Prankishor began his Dynamic Programming journey here.
//Dynamic Programming (Basic Problem #1)
// 0/1 Knapsack Problem 

#include<bits/stdc++.h>
using namespace std;

//Method 1: Using simple Recursion


int knapsack(int n, int weight[], int profit[], int bag)
{
	// base condition, if no more element in array or no more capacity in knapsack, then return 0
	// that is no more adding of profit
	if(n==0||bag==0) 
	
	{
		return 0;
	}
	
	//We will start from the last element in the array and see if we can include it in our bag
	//to include it, we will ofcourse have to see if the weight is less than or equal to our bag's capacity
	if(weight[n-1]<= bag)
	{
		//if yes, then we have two choices. To include the item or to not include. For that we need to check the 
		//profit, because we will see which choice gives us the more profit (including it or not including it)
		//that is what the next line of code is, profit + (include) or no profit (no include) -> we take the max
		return max(profit[n-1] + knapsack(n-1, weight, profit, bag-weight[n-1]), knapsack(n-1, weight, profit, bag));
	}
	
	//if we the item is overweight than ofcourse we dont include it.
	else if(weight[n-1]>bag)
	{
		return knapsack(n-1, weight, profit, bag);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------



//Method 2: Memoization 

//for memoization, we only need to add two lines in recursive solution. 
//We will create a 2D array say dp[][], and pass the size to dp of those parameter that kept on changing while
//we were recursively calling the function. One was "n" and the other was "bag".
//Declare the array globally to avoid problems.

int dp[6][101];

int knapsackMemo(int n, int weight[], int profit[], int bag)
{
	// base condition, if no more element in array or no more capacity in knapsack, then return 0
	// that is no more adding of profit
	if(n==0||bag==0) 
	
	{
		return 0;
	}
	
	//(NEW LINE IN MEMOIZATION)
	//Here, we check if the value present in dp table for the given element and bag capacity is already there.
	//if it is, we will return form here instead of again recursively checking it.
	if(dp[n][bag]!=-1)
	{
		return dp[n][bag];
	}
	
	//We will start from the last element in the array and see if we can include it in our bag
	//to include it, we will ofcourse have to see if the weight is less than or equal to our bag's capacity
	if(weight[n-1]<= bag)
	{
		//if yes, then we have two choices. To include the item or to not include. For that we need to check the 
		//profit, because we will see which choice gives us the more profit (including it or not including it)
		//that is what the next line of code is, profit + (include) or no profit (no include) -> we take the max
		
		//NEW LINE
		//Here instead of returning, we are saving the value if it is occuring first time
		//return dp[n][bag] = max(profit[n-1] + knapsackMemo(n-1, weight, profit, bag-weight[n-1]), knapsackMemo(n-1, weight, profit, bag));
		
		if(profit[n-1] + knapsackMemo(n-1, weight, profit, bag-weight[n-1])>knapsackMemo(n-1, weight, profit, bag))
		{
			return dp[n][bag]=profit[n-1] + knapsackMemo(n-1, weight, profit, bag-weight[n-1]);
		}
		else
		{
			return dp[n][bag]=knapsackMemo(n-1, weight, profit, bag);
		}
		
	}
	
	//if we the item is overweight than ofcourse we dont include it.
	else if(weight[n-1]>bag)
	{
		return dp[n][bag] = knapsackMemo(n-1, weight, profit, bag);
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Method 3: Tabulation (BEST METHOD)
//This method totally omits the idea of recursion
//Why is this said to be better in some cases? Because when we use recurions, sometimes the calls are so many in numbers that our recursion stack
//gets overflowed and we get error. So in this case we can use tabulation.
//Example for this error in problem is Scrambbled String 

//So how to implement tabulation? (2) steps!
//STEP 1: Initialize the dp matrix (First column and first row) with zero.
//It is done to replace the base condition of recursion


//STEP 2: Change the recursive code to tabulation, that is we will fill the remaining matrix with the help of the previous values in the matrix
//It is done in very simple way, see the code to understand (basically we replace recursion code) in a way that we store values in dp
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
				dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
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
	int n = 5;
	//weight of items
	int weight[n] = {20, 30, 10, 40, 70};
	//profit of items
	int profit[n] = {30, 60, 40, 10, 12};
	//capacity of our bag (knapsack)
	int bag = 100;
	
	//This line is for solution 2. memset initializes all the values to of a array to given value (-1 in this case)
	memset(dp, -1, sizeof(dp));
	
	//Call recursive funtion
	//int maxProfit = knapsack(n, weight, profit, bag);
	
	//Call Memo funtion
	int maxProfit = knapsackMemo(n, weight, profit, bag);
	cout<<maxProfit<<endl;
	
	//Call Tabulation Function
	//int maxProfit = knapsackTab(n, weight, profit, bag);
	//cout<<maxProfit<<endl;
}
