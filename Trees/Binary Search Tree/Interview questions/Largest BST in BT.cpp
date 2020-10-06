#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;

	node *left, *right;
	
	
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printInorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void checkInorder(node *root, vector<int> &v)
{
	if(root==NULL)
	{
		return;
	}
	
	checkInorder(root->left, v);
	v.push_back(root->data);
	checkInorder(root->right, v);
}
int largestBST(node *root)
{
	vector<int> v;
	checkInorder(root, v);
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int count = 0;
	int max = INT_MIN;
	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i]<v[i+1])
		{
			count++;
			if(max<count)
			{
				max = count;
			}
		}
		else 
		{
			count = 0;
		}
	}
	if(count<max)
	{
		max = count;
	}
	return max+1;
	
}
int main()
{
	node *root = new node(25);
	root->left = new node(18);
	root->right = new node(50);
	root->left->left = new node(19);
	root->left->right = new node(20);
	root->right->left = new node(35);
	root->right->right = new node(60);
	root->left->left->right = new node(15);
	root->left->right->left = new node(18);
	root->left->right->right = new node(25);
	root->right->left->left = new node(20);
	root->right->left->left->right = new node(25);
	root->right->left->right = new node(40);
	root->right->right->left = new node(55);
	root->right->right->right = new node(70);
	
	printInorder(root);
	cout<<endl;
	cout<<largestBST(root)<<endl;
	
}
