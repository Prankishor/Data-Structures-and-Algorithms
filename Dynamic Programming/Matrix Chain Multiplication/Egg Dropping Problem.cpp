#include<bits/stdc++.h>
using namespace std;


//Recursive Approach
int solve(int f, int e)
{
	if(f==0 || f==1)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	int mn = INT_MAX;
	
	for(int k=1; k<=f; k++)
	{
		//max because we are finding worst cases 
		//solve(k-1,e-1) when egg breaks and solve(f-k, e) when egg doesnt break
		int temp =max(solve(k-1,e-1), solve(f-k, e));
		if(temp<mn)
		{
			mn = temp;
		}
	}
	return mn+1;
}

//Memoized Approach 

int dp[51][11];
int solveM(int f, int e)
{
	if(f==0 || f==1)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	
	//change
	if(dp[f][e] !=-1)
	{
		return dp[f][e];
	}
	int mn = INT_MAX;
	
	for(int k=1; k<=f; k++)
	{
		//max because we are finding worst cases 
		//solve(k-1,e-1) when egg breaks and solve(f-k, e) when egg doesnt break
		int temp =max(solve(k-1,e-1), solve(f-k, e));
		if(temp<mn)
		{
			mn = temp;
		}
	}
	//change
	return dp[f][e] = mn+1;
}

//Memoized Optimization

int solveMO(int f, int e)
{
	if(f==0 || f==1)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	
	//change
	if(dp[f][e] !=-1)
	{
		return dp[f][e];
	}
	int mn = INT_MAX;
	
	for(int k=1; k<=f; k++)
	{
		//max because we are finding worst cases 
		//solve(k-1,e-1) when egg breaks and solve(f-k, e) when egg doesnt break
		int temp =max(solve(k-1,e-1), solve(f-k, e));
		if(temp<mn)
		{
			mn = temp;
		}
	}
	//change
	return dp[f][e] = mn+1;
}

int main()
{
	int floors, eggs;
	cin>>eggs>>floors;
	memset(dp, -1, sizeof(dp));
	int ans = solveMO(floors, eggs);
	cout<<ans<<endl;
}
