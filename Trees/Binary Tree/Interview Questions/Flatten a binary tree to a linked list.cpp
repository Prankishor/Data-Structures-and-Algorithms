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


void flatten(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return;
	}
	
	if(root->left)
	{
		flatten(root->left);
		
		node *tempR = root->right;
		root->right = root->left;
		root->left = NULL;
		
		node *temp = root->right;
		while(temp->right !=NULL)
		{
			temp = temp->right;
		}
		temp->right = tempR;
	}
	flatten(root->right);
}


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


int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(3);
	root->left->right = new node(4);
	root->right->right = new node(6);
	
	flatten(root);
	printInorder(root);
	
	
	
}
