#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int index)
{
	if(index == a.size())
	{
		ans.push_back(a);
		return;
	}

	//eg: 123
	//First 123 store hobo,then return hua pisot forloop end hbo, and then 
	//agor call tule return hobo jot 1 index asil and 1 i asil.
	//for loop solibo and i=2 hoi jabo and 123 tu 132 hoi jabo.
	//heneke pisfalor pora combinations boni boni ahibo

	for(int i=index; i<a.size(); i++)
	{
		swap(a[i],a[index]);
		permute(a, index+1);
		swap(a[i], a[index]); //backtracking
	}
	return;
}

int main()
{
	int n;
	cin>>n;

	vector<int> a(n);
	for(auto &i:a)
	{
		cin>>i;
	}

	permute(a,0);

	for(auto i:ans){
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}

}
