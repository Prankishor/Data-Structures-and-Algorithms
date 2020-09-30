//Prankishor (21)
//Dynamic Programming
//Problem: Longest repeating subsequence (Jo char repeat ho rahe ho)
//Approach: given string ko aur ek string me lelo phir dono ka lcs nikalo lekin if i==j hai then wo count mat karo. Arrey 
//diagram banake dekho.

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
			//Here is the addition
			if(s1[i-1]==s2[j-1] && i!=j)
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
		int n;
		cin>>n;
		
		string s1,s2;
		cin>>s1;
		s2=s1;

		lcsT(s1, s2, n, n);
	}
	return 0;
}

