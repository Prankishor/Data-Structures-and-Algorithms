//Prankishor (21)
//Dynamic Programming
//Problem: Longest Common Subsequence 
//Explanation: Given two strings x and y, return the maximum number of matches of characters between them

//Method 1: Recursion
//Base condition (n = size of x,  m = size of y) , so if (n==0 || y ==0 ) return 0.
//Choice diagram: if (x[n-1] == y[m-1]) return x[n-1] and y[m-1] else maximum of ((x[n-1], y[m]), (x[n], y[m-1))

#include<bits/stdc++.h>
using namespace std;

/*//int t[101][101]; // used for memoization
int lcs(string s1, string s2, int n, int m)
{
	if(n==0 || m==0)
	{
		return 0;
	}
	
	if(s1[n-1] == s2[m-1])
	{
		return 1+lcs(s1, s2, n-1, m-1);
	}
	else
	{
		return max(lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

//Method 2: Memoization

int lcsM(string s1, string s2, int n, int m)
{
	if(n==0 || m==0)
	{
		return 0;
	}
	
	if(t[n][m]!=-1)
	{
		return t[n][m];
	}
	
	if(s1[n-1] == s2[m-1])
	{
		return t[n][m] = 1+lcs(s1, s2, n-1, m-1);
	}
	else
	{
		return  t[n][m] = max(lcs(s1,s2,n-1,m), lcs(s1,s2,n,m-1));
	}
}*/

//-------------------------------------------------------------------------------------------------------------------------------------

//Method 3: Tabulation

void lcsT(string s1, string s2, int n, int m)
{
	int dp[n+1][m+1];
	
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<m+1; j++)
		{
			if(i==0 || j==0)
			{
			    dp[i][j] = 0;
		    }
		}
	}
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<m+1; j++)
		{
			if(s1[i-1]==s2[j-1])
		    {
		    	dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	cout<<dp[n][m]<<endl;

}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		string s1,s2;
		cin>>s1>>s2;
		
		
		//cout<<lcs(s1, s2, n, m)<<endl;
		//memset(dp, -1, sizeof(dp));
		//cout<<lcsM(s1, s2, n, m)<<endl;
		lcsT(s1, s2, n, m);
	}
	return 0;
}

