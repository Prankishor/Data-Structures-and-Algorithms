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


//Recursive function where we search for the two given nodes. If we dont find any, we return NULL, if we find the node, we return the node.
bool check(node *p, node *q)
{
	if(p == NULL && q == NULL)
	{
		return 1;
	}
	
	if(p!=NULL && q!=NULL)
	{
		if(p->data == q->data && check(p->left, q->left) && check(p->right, q->right))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->left->right->left = new node(7);
	
	
	node *root2 = new node(1);
	root2->left = new node(2);
	root2->right = new node(3);
	root2->left->left = new node(4);
	root2->left->right = new node(5);
	root2->right->left = new node(6);
	root2->left->right->left = new node(7);
	
	cout<<check(root, root2);
	
}
