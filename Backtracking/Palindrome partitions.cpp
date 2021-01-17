#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//USE ll NOT int

bool isPlaindrom(string str, int start, int end)
{
	while(start<end)
	{
		if(str[start]!= str[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void helper(vector<vector<string>> &allPart, vector<string> &currPart, int start, int n, string str)
{
	if(start>=n)
	{
		allPart.push_back(currPart);
		return;
	}

	for(int i=start; i<n; i++)
	{
		if(isPlaindrom(str, start, i))
		{
			currPart.push_back(str.substr(start, i-start+1));

			helper(allPart, currPart, i+1, n, str);

			currPart.pop_back();
		}
	}
}

void allPalPartitions(string str)
{
	int n = str.length();

	vector<vector<string>> allPart;
	vector<string> currPart;

	helper(allPart, currPart, 0, n, str);


	for(int i=0; i<allPart.size(); i++)
	{
		for(int j=0; j<allPart[i].size(); j++)
		{
			cout<<allPart[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	string str = "nitin"; 
    allPalPartitions(str); 
    return 0; 
}


