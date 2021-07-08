#include<bits/stdc++.h>
using namespace std;

#define ll        long long 
#define pb        push_back
#define mem1(a)   memset(a, -1, sizeof(a))
#define mem0(a)	  memset(a, 0, sizeof(a))

const long long MOD = 1e9+7;
const long long INF = 1e18;


//PASTE Requirements

bool subsetSum(int arr[], int sum, int n){
	if(sum>0 && n==0){
		return false;
	}
	if(sum==0){
		return true;
	}

	if(arr[n-1]<=sum)
	{
		return subsetSum(arr, sum-arr[n-1], n-1) || subsetSum(arr, sum, n-1);;
	}
	else
	{
		return subsetSum(arr, sum, n-1);
	}
}

void solve()
{
	int n, sum;
	cin>>n>>sum;
	int arr[n];

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	if(subsetSum(arr, sum, n)==true)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
//--------------------------------------------------\\

int main()
{
	int t;
	t=1;
	//cin>>t;

	while(t--)
	{
		solve();
	}	
	return 0;
}


