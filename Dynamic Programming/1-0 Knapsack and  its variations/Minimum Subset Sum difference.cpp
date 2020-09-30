//DYNAMIC PROGRAMMING 
//PROBLEM 5: Minimum Subset sum difference 
//Concept: (1)We need to find two subsets from given array arr, whose difference would be minimum. Now we know that the minimum sum of any of its subset
//will be 0 and the maximum can be the sum itself. So the range is 0-sum. 
//(2) We can also say that s2+s1 = sum, therefore if we find s1, s2 apne aap niklega
//(3) Here s1 , we will always take small, so Range - 2s1 = always minimum.
//(4) Therefore, use subsetSum concept and make a dp table for sum and elements of array
//(5) Now take the last row of dp and from sum/2 to 0 (since s1 will be there somewhere between sum/2 to 0), take the first element you find and
//(6) return it like the above formula (sum-2*s1) 
#include<bits/stdc++.h>
using namespace std;
//Same subsetSum program
int subsetSum(int a[], int n, int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0; i<sum+1; i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0; i<n+1; i++)
	{
		dp[i][0] = 1;
	}
	
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(a[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
			}
			else
			{
				dp[i][j]= dp[i-1][j];
			}
		}
	}
	//returning the highest value of the last row of dp table between sum/2 to 0
	int diff = INT_MAX;
	for (int j=sum/2; j>=0; j--) 
    {  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
     
}


//this is just helper method to calculate the sum
int findMin(int a[], int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
	}
	return subsetSum(a, n, sum);
	
	
}

int main()
{
	int n = 4;
	int a[n] = {36, 7, 46, 40};
	
	int ans = findMin(a, n);
	cout<<"The minimum difference between two subsets: "<<ans<<endl;
}
