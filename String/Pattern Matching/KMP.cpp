#include<bits/stdc++.h>
using namespace std;

void createLPS(string pat, int m, int* lps);
void KMPSearch(string pat, string txt)
{
	int n = txt.size();
	int m = pat.size();
	
	int lps[m];
	createLPS(pat, m, lps);
	
	int i=0;
	int j=0;
	
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			j++;
			i++;
		}
		
		if(j==m)
		{
			cout<<"Pattern found at index "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<n && pat[j]!=txt[i]){
			
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	
	
}

void createLPS(string pat, int m, int *lps)
{
	lps[0]=0;
	int i=1;
	int j=0;
	while(i<m)
	{
		if(pat[i]==pat[j])
		{
			j++;
			lps[i]=j;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}

}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	
	KMPSearch(pat, txt);
	
}
