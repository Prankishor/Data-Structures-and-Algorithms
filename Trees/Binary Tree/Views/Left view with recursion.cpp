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


void printLeftView(node *root, int &maxlevel, int curlevel)
{
	if(root == NULL)
	{
		return;
	}
	
	if(maxlevel<curlevel)
	{
		cout<<root->data<<" ";
		maxlevel = curlevel;
	}
	
	printLeftView(root->left, maxlevel, curlevel+1);
	printLeftView(root->right, maxlevel, curlevel+1);
	
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
	
	int maxlevel = 0;
	int curlevel = 1;
	printLeftView(root, maxlevel, curlevel);
	
}
