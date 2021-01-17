#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define prime 119

ll createHashValue(string s, int n)
{
	ll result = 0;
	for(int i=0; i<n; i++)
	{
		result+=(ll)(s[i]*(ll)pow(prime, i));
	}
	return result;
}

ll recalculateHash(string s, int oldIndex, int newIndex, ll oldHash, int patlen)
{
	ll newHash = oldHash - s[oldIndex];
	newHash/=prime;
	newHash+=(ll)(s[newIndex]*(ll)(pow(prime, patlen-1)));
	return newHash;
}


int main()
{
	string s = "My name is Anthony Talukdar";
	string p = "thon";
	
	ll patHash = createHashValue(p, p.size());
	ll sHash = createHashValue(s, p.size());
	
	for(int i=0; i<=s.size()-p.size(); i++)
	{
		if(patHash == sHash)
		{
			cout<<"FOUND"<<endl;
			return 0;
		}
		
		if(i<s.size()-p.size())
		{
			sHash = recalculateHash(s, i, i+p.size(), sHash, p.size());
		}
	}
	cout<<"NOT FOUND"<<endl;
}
