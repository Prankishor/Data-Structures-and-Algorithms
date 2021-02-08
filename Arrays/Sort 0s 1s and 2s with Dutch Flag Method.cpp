#include<bits/stdc++.h>
using namespace std;
#define int long long 
const long long MOD = 1e9+7;

//PASTE Requirements


//---------------------SOLUTION--------------------\\


void solve()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	int low = 0;
	int high = n-1;
	int mid = 0;

	while(mid<=high)
	{
		if(a[mid] == 0)
		{
			swap(a[low], a[mid]);
			mid++;
			low++;
		}
		else if(a[mid] == 2)
		{
			swap(a[mid], a[high]);
			high--;
		}
		else
		{
			mid++;
		}
	}

	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}

//--------------------------------------------------\\

int32_t main()
{
	solve();	
}

