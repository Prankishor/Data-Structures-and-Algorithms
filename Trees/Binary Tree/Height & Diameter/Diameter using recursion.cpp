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

int printDiameter(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int lheight = printHeight(root->left);
	int rheight = printHeight(root->right);
	
	int ldiameter = printDiameter(root->left);
	int rdiameter = printDiameter(root->right);
	
	//lheight + rheight + 1 = diameter passing through root
	//ldiameter, rdiameter = diameter not passing through root
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
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
	
	cout<<printDiameter(root);
	
}
