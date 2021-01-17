#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//USE ll NOT int


bool contains(string dict[], string prefix,int n)
{
	for(int i=0; i<n; i++)
	{
		if(dict[i].compare(prefix)==0)
		{
			return true;
		}
	}
	return false;
}

void wordbreak(string sentence, string dict[], int len, string result,int n)
{
	for(int i=1; i<=len; i++)
	{
		string prefix = sentence.substr(0, i);

		if(contains(dict, prefix, n))
		{
			if(i==len)
			{
				result+=prefix;
				cout<<result<<endl;
				return;
			}

			wordbreak(sentence.substr(i, len-i), dict, len-i, result+prefix+" ", n);
		}

	}
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		string dict[n];

		for(int i=0; i<n; i++)
		{
			cin>>dict[i];
		}

		string sentence;
		cin>>sentence;

		int len = sentence.size();

		wordbreak(sentence, dict, len, "", n);
	}
}



