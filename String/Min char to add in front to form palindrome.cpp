#include<bits/stdc++.h>
using namespace std;

void getLPS(string concat, int *lps)
{
	int n = concat.size();
	lps[0]=0;
	int i=1;
	int j=0;
	
	while(i<n)
	{
		if(concat[i]==concat[j])
		{
			j++;
			lps[i]=j;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

void getMinChar(string str)
{
	string rev = str;
	reverse(rev.begin(), rev.end());
	string concat = str + "$" + rev;
	
	int n = concat.size();
	int lps[n];
	getLPS(concat, lps);
	
	cout<<str.size()-lps[n-1]<<endl;
}

int main()
{
    string str = "AACECAAAA"; 
    getMinChar(str); 
    return 0;
	
}
