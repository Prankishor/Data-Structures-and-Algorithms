//Dynamic Programming
//Problem: Matrix Chain Multiplication
//To solve problems based on MCM and to get familiar, remember a format: 
//(i) Find i and j in array (ii) take out base condition (iii) Take out loop limit (k will run from where to where)
//(iv) see what you want to calculate.

//To understand the problem, read the question.

//Method 1: Recursion

#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int i, int j)
{
	//2nd step, the base condition, if i becomes = to j, we will have only one element, but we need to elements for 
	//multiplication
	if(i>=j)
	{
		return 0;
	}
	
	//It is important here to initialize min here, because every recursive call, we need new min.
	//Dry RUN
	int mn=INT_MAX;
	int temp;
	
	for(int k=i; k<=j-1; k++)
	{
		//last one is derived formula after running through the problem
		temp = solve(a, i, k)+solve(a,k+1, j)+(a[i-1]*a[k]*a[j]);
		if(temp<mn)
		{
			mn = temp;
		}
	}
	return mn;
	
	
}

//Method 2: Memoization 

int dp[101][101];

int solveM(int a[], int i, int j)
{
	
	if(i>=j)
	{
		return 0;
	}
	
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}

	int mn=INT_MAX;
	int temp;
	
	for(int k=i; k<=j-1; k++)
	{
		
		temp = solve(a, i, k)+solve(a,k+1, j)+(a[i-1]*a[k]*a[j]);
		if(temp<mn)
		{
			mn = temp;
		}
	}
	return dp[i][j] =  mn;
	
	
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
//first step, we pass i and j by thinking and deciding after seeing the problem
//int ans = solve(a, 1, n-1); //i=1, j=n-1
int ans = solveM(a, 1, n-1);
	cout<<ans<<endl;
}
