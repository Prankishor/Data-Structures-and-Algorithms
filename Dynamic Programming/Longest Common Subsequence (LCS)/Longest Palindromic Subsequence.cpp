//Dynamic Programming 
//Problem: Longest Palindromic Subsequence 
//Input is single string, in this question we can derive the second string by reversing the given string. LCS between them
//is the answer

#include<bits/stdc++.h>
using namespace std;
int lcsT(string s1, string s2, int n, int m)
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
	
	return dp[n][m];

}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		string s1;
		cin>>s1;
		string s2 = string(s1.rbegin(), s1.rend());
		
		cout<<lcsT(s1, s2, n, n)<<endl;
	}
	return 0;
}
