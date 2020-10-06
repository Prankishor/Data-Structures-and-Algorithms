//O(N^2)

#include<bits/stdc++.h>
using namespace std;

//A blue print of what tree will contain
struct node{
	//a variable to store data
	int data;
	//left and right named user defined pointers to point to it's child nodes.
	node *left, *right;
	
	//user defined function to create a node.
	node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool isBalanced(node *root, int &height)
{
	int lh = 0;
	int rh = 0;
	
	int lb=0, rb=0;
	if(root==NULL)
	{
		height = 0;
		return 1;
	}
	
	lb = isBalanced(root->left, lh);
	rb = isBalanced(root->right, rh);
	
	height = (lh>rh?lh:rh)+1;
	
	if(abs(lh-rh)>=2)
	{
		return 0;
	}
	else 
	{
		return lb && rb;
	}
	
}

int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
    root->left->left->left = new node(8);   
	int height = 0;
	int ans = isBalanced(root, height);
	cout<<ans<<endl;
	
}
