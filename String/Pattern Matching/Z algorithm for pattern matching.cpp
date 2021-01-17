#include<bits/stdc++.h>
using namespace std;

void getzarray(string concat, int Z[])
{
	int L, R, K;
	
	int n = concat.size();
	
	L = R = 0;
	
	for(int i=1; i<n; i++)
	{
		if(i>R)
		{
			L = R = i;
			
			while(R<n && concat[R-L] == concat[R])
			{
				R++;
			}
			Z[i] = R-L;
			R--;
		}
		else
		{
			//introduce K
			
			K = i-L;
			
			if(Z[K]<R-i+1)
			{
				Z[i] = Z[K];
			}
			else
			{
				L=i;
			while(R<n && concat[R-L] == concat[R])
			{
				R++;
			}
			Z[i] = R-L;
			R--;
				
			}
		}
	}
}


void search(string text, string pat)
{
	string concat = pat + "$" + text;
	int l = concat.size();
	int Z[l];
	
	//The function that will make the z array for us
	getzarray(concat, Z);
	
	for(int i=0; i<l; i++)
	{
		if(Z[i] == pat.size())
		{
			cout<<"Pattern found at index: "<<i-pat.size()-1<<endl;
		}
	}
}

int main()
{
	string text = "GEEKS FOR GEEKS";
	string pattern = "GEEK";
	
	search(text, pattern);
	return 0;
}
