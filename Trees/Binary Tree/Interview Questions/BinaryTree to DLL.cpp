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


void BTtoDLL(node *root, node **head)
{
	if(root==NULL)
	{
		return;
	}
	static node *prev = NULL;
	BTtoDLL(root->left, head);
	if(prev==NULL)
	{
		*head = root;
	}
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	
	BTtoDLL(root->right, head);
	
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
	node *head = NULL;
	BTtoDLL(root, &head);
	node *t = head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->right;
	}
	cout<<endl;
	//printInorder(root);
	
	
	
}
