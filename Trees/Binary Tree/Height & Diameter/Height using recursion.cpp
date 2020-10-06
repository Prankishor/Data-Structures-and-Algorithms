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


//int h = 0;

int printHeight(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int left = printHeight(root->left);
	int right = printHeight(root->right);
	
	if(left>right)
	{
		return left+1;
	}
	else
	{
		return right+1;
	}
	
}

int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->left->left = new node(7);
	
	cout<<printHeight(root);
	
}
