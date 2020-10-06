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

//left->parent->right
void printInorder(node *root)
{
	stack<node *> s;
	node *cur = root;
	
	//idea is to move cur to the left most node->left (that is null) and when it is reached,
	//print its parent that is the actual left most node
	// and move to its right if present else backtrack (pop from stack) 
	while(cur!=NULL || s.empty()==false)
	{
		while(cur!=NULL)
		{
			s.push(cur);
			cur=cur->left;
		}
		cur = s.top();
	    s.pop();
	    cout<<cur->data<<" ";
	    cur = cur->right;
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
	
	printInorder(root);
	
}
