//Prankishor (21)
//Dynamic Programming
//Problem: Longest Common substring (variation on LCS)
// The only change is, when ever we encounter different elements, we start from 0 again, and return the max value of dp, see code

#include<bits/stdc++.h>
using namespace std;

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
				//Here is the change.
				dp[i][j]=0;
			}
		}
	}
	
	int maxValue = INT_MIN;
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<m+1; j++)
		{
			if(dp[i][j]>maxValue)
			{
				maxValue=dp[i][j];
			}
		}
	}
	
	cout<<maxValue<<endl;

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
	
		lcsT(s1, s2, n, m);
	}
	return 0;
}

