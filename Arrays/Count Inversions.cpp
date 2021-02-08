//COUNT INVERSIONS PROBLEM
//DESCRIPTION: Count no. of pairs in a given array a, where i<j and a[i]>a[j]

//This code is optimal solution using merge sort

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int invCount = 0;
	
	i=left;
	j=mid;
	k=left;
	
	while((i<=mid-1) && (j<=right)){
		if(arr[i]<=arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			invCount+=mid-i; 
		}
	}
	
	while(i<=mid-1)
	{
		temp[k++] = arr[i++];
	}
	while(j<=right)
	{
		temp[k++] = arr[j++];
	}
	for(i=left; i<=right; i++)
	{
		arr[i] = temp[i];
	}
	
	return invCount;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int invCount=0, mid;
	
	if(right>left){
		
		mid = (left+right)/2;
		
		invCount+=_mergeSort(arr, temp, left, mid);
		invCount+=_mergeSort(arr, temp, mid+1, right);
		
		invCount+=merge(arr, temp, left, mid+1, right);
		
	}
	return invCount;
}


int main()
{
	int arr[] = {5, 3, 2, 4, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int temp[n];
	int ans = _mergeSort(arr, temp, 0, n-1);
	cout<<ans<<endl;
}
