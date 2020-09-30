//Dynamic Programming 
//Problem: Palindrome Partition
//Explanation: Will have to break the string into min number of groups to make all 
//of the subgroups of the string palindrome independently 
//For Eg: zabay (z/ aba / y) (2 partitions) (Yes partition = number of "/" )

#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string s, int i, int j)
{
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int palindromPart(string s, int i, int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(isPalindrom(s, i, j)==true)
	{
		return 0;
	}
	
	int mn = INT_MAX;
	int temp;
	for(int k=i; k<j; k++)
	{
		temp= palindromPart(s, i, k) + palindromPart(s, k+1, j) + 1;
		if(temp<mn)
		{
			mn=temp;
		}
	}
	return mn;
	
}

//Method 2: Memoization

int dp[1001][1001]; 
int palindromPartM(string s, int i, int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(isPalindrom(s, i, j)==true)
	{
		return 0;
	}
	
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	
	int mn = INT_MAX;
	int temp;
	for(int k=i; k<j; k++)
	{
		temp= palindromPartM(s, i, k) + palindromPartM(s, k+1, j) + 1;
		if(temp<mn)
		{
			mn=temp;
		}
	}
	return dp[i][j]=mn;
	
}

//Method 2:Further Optimization in Memoization
int palindromPartMO(string s, int i, int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(isPalindrom(s, i, j)==true)
	{
		return 0;
	}
	
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	
	int mn = INT_MAX;
	int temp;
	for(int k=i; k<j; k++)
	{
		int left, right;
		
		if(dp[i][k]!=-1)
		{
			left = dp[i][k];
		}
		else
		{
			left = palindromPartMO(s, i, k);
		}
		
		if(dp[k+1][j]!=-1)
		{
			right = dp[k+1][j];
		}
		else
		{
			right = palindromPartMO(s, k+1, j);
		}
		temp= left + right  + 1;
		if(temp<mn)
		{
			mn=temp;
		}
	}
	return dp[i][j]=mn;
	
}



int main()
{
	string s;
	cin>>s;
	
	//i = 0, j = n-1
	//int ans = palindromPart(s, 0, s.size()-1);
	
	memset(dp, -1, sizeof(dp));
	//int ans = palindromPartM(s, 0, s.size()-1);
	int ans = palindromPartMO(s, 0, s.size()-1);
	
	cout<<ans<<endl;
	
}
