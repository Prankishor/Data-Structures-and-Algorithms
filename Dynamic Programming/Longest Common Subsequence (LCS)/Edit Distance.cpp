#include<bits/stdc++.h>
using namespace std;

//RECURSION
int editDistance(string s1, string s2, int i, int j)
{
	//Jodi first string khotom hoise, baki operation khini
	//add koribo logia operation hoi
	if(i==s1.size())
	{
		return s2.size()-j;
	}
	if(j==s2.size())
	{
		return s1.size()-i;
	}
	if(s1[i]==s2[j])
	{
		return editDistance(s1, s2, i+1, j+1);
	}
	else
	{
		int addition = 1+editDistance(s1, s2, i, j+1);
		int removal = 1+editDistance(s1, s2, i+1, j);
		int same = 1+editDistance(s1, s2, i+1, j+1);
		return min(addition, min(removal, same));
	}
	
}



int dp[101][101];
//Memoization
int editDistanceM(string s1, string s2, int i, int j)
{
	
	if(i==s1.size())
	{
		return s2.size()-j;
	}
	if(j==s2.size())
	{
		return s1.size()-i;
	}
	if(s1[i]==s2[j])
	{
		return dp[i][j]= editDistance(s1, s2, i+1, j+1);
	}
	
	else
	{
		int addition = 1+editDistance(s1, s2, i, j+1);
		int removal = 1+editDistance(s1, s2, i+1, j);
		int same = 1+editDistance(s1, s2, i+1, j+1);
		return dp[i][j] = min(addition, min(removal, same));
	}
	
	
}

//Tabulation
int editDistanceT(string s1, string s2, int n, int m)
{
	
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=m; j++)
		{
			if(i==0)
			{
				dp[i][j] = j;
			}
			else if(j==0)
			{
				dp[i][j] = i;
			}
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else {
				dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
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
		int n,m;
		cin>>n>>m;
		
		memset(dp, -1, sizeof(dp));
		string s1,s2;
		cin>>s1>>s2;
		//pass i and j = 0
		cout<<editDistanceT(s1, s2, s1.size(), s2.size())<<endl;
	}
}
