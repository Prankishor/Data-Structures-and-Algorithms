//Dynamic Programming 
//Practice problem 3 
//Vairant of Knapsack ->  EqualSumPartition
//PROBLEM: If given an array , print true if the array can be divided into two subsets whose sum is equal to each other
//Method: Tabulation
#include<bits/stdc++.h>
using namespace std;


bool subset(int n, int sum, int a[])
{
	bool dp[n+1][sum+1];
	
	for(int i=0; i<=n; i++)
	{
		dp[i][0]= true;
	}
	
	for(int i=1; i<=sum; i++)
	{
		dp[0][i]= false;
	}
	
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(a[i-1]<=sum)
			{
				dp[i][j]= dp[i-1][j-a[i-1]] || dp[i-1][j];
			}
			else
			{
				dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}


bool equalSum(int n, int a[])
{
	int sum = 0;
	bool ans;
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
	}
	
	//if sum of all the elements is not even then we obviously cannot divide it into two partition, eg: given elements whose sum is 22,
	//we can divide it into 11 and 11 but if 23 is the sum then one subset has to be 11 and other 12
	if(sum%2!=0)
	{
		return false;
	}
	
	//Now we only have to find a subset whose sum is = sum/2. Because the remainin subset's sum will anyway be sum/2.
	//It is reduced to Subset Sum problem now.
	else
	{
		ans = subset(n, sum/2, a);
		
	}
	
	return ans;
	
}

int main()
{
	int n = 7;
	int a[n] = {4,3,2,3,5,2,1};
    cout<<equalSum(n, a)<<endl;
}
