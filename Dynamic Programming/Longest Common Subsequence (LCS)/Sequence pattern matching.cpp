//Prankishor (21)
//Dynamic Programming
//Problem: Sequence pattern matching
//Take out lcs and see if the length matches the pattern length
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
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	if(dp[n][m] == m)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"fales"<<endl;
	}

}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		string s1,s2; //s2 = pattern
		cin>>s1>>s2;
		
		lcsT(s1, s2, n, m);
	}
	return 0;
}

