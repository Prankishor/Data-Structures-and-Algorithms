#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int index)
{
	if(index == a.size())
	{
		ans.push_back(a);
		return;
	}


	for(int i=index; i<a.size(); i++)
	{
		//Taaki ek baar chale aur initial given number store ho jaye isliye i!=index
		//baki if for eg 122 toh 2 and 2 ko swap karke fayda nahi hume duplicates nahi chahiye
		if(i!=index && a[i]==a[index])
		{
			continue;
		}
		swap(a[i],a[index]);
		helper(a, ans, index+1);
		swap(a[i], a[index]); //backtracking
	}
	return;
}
vector<vector<int>> permute(vector<int> a)
{
	sort(a.begin(), a.end());
	vector<vector<int>> ans;
	helper(a, ans, 0);
	return ans;
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

	vector<vector<int>> ans;

	ans = permute(a);

	for(auto i:ans){
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}

}
