#include<bits/stdc++.h>
using namespace std;
#define d 256
bool pattern(string s, string p, int prime)
{
	int sOfP = p.size();
	int sOfS = s.size();
	int h = 1;
	int hashOfP = 0;
	int hashOfS = 0;
	
	for(int i=0; i<sOfP-1; i++)
	{
		h = (h*d)%prime;
	}
	
	
	for(int i=0; i<sOfP; i++)
	{
		hashOfP = (d*hashOfP+p[i])%prime;
		hashOfS = (d*hashOfS+s[i])%prime;
	}
	
	for(int i=0; i<=sOfS-sOfP; i++)
	{
		if(hashOfP == hashOfS)
		{
			//also can check one by one
			return true;
		}
		
		if(i<sOfS-sOfP)
		{
			hashOfS = (d*(hashOfS-s[i]*h)+s[i+sOfP])%prime;
			
			if(hashOfS < 0)
			{
				hashOfS+=prime;
			}
		}
	}
	return false;
	
}

int main()
{
	string s = "My name is Anthony Talukdar";
	string p = "thon";
	int prime = 101;
	
	bool check = pattern(s, p, prime);
	
	if(check)
	{
		cout<<"Pattern found"<<endl;
	}
	else
	{
		cout<<"Pattern not found"<<endl;
	}
}
