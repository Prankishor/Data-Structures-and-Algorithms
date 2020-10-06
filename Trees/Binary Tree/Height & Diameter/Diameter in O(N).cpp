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

int printDiameter(node *root, int &height)
{
	int lh = 0;
	int rh = 0;
	
	int ldiameter = 0;
	int rdiameter = 0;
	
	if(root==NULL)
	{
		height = 0;
		return 0;
	}
	
	ldiameter =  printDiameter(root->left, lh);
	rdiameter =  printDiameter(root->right, rh);
	
	height = max(lh, rh) + 1;
	return max(lh + rh + 1, max(ldiameter, rdiameter));
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
	int height = 0;
	cout<<printDiameter(root, height);
	
}
