//Dynamic Programming 
//Practice problem 2 
//Vairant of Knapsack -> SUBSET SUM
//PROBLEM: If given an array and a number k, print true if a subset is possible whose sum is k
//Method: Tabulation
#include<bits/stdc++.h>
using namespace std;

bool subset(int n, int sum, int a[])
{
	//Initialize:
	
	/*for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0)
			{
				dp[i][j]=false;
			}
			if(j==0)
			{
				dp[i][j]=true;
			}
		}
	}*/
	
	bool dp[n+1][sum+1];
	
	//Make the first column true
	for(int i=0; i<=n; i++)
	{
		dp[i][0]=true;
	}
	
	//Make the first row false, except for the first element cause if n=0 and sum = 0,
	//i cannot create a subset of sum 0 if there are no elements so false
	for(int i=1; i<=n; i++)
	{
		dp[0][i]=false;
	}
	
	//Logic
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			//if the element in array is less then the required sum
			if(a[i-1]<=j) 
			{
			
			    //Ya to store karenge ya nahi karenge (Remember choice diagram?)
				dp[i][j]= dp[i-1][j-a[i-1]] || dp[i-1][j];
			}
			else
			{
				//if a[i-1] > then sum then obviously wont store it, so will pass that element as it is, n will decrease (i-1) but sum will remain same(j)
				dp[i][j] =dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
	
}

int main()
{
	int n = 4;
	int a[n] = {1,5,11,5};
	int sum = 21;
    cout<<subset(n, sum, a)<<endl;
}
