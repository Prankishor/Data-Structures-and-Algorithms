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

//Use stack
//push root
//pop and print
//push popped element's right child
//push popped element's left child
//do this until stack is empty
void printPreorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	stack<node*> s;
	
	s.push(root);
	
	while(!s.empty())
	{
		node *cur = s.top();
		cout<<cur->data<<" ";
		s.pop();
		
		if(cur->right)
		{
			s.push(cur->right);
		}
		if(cur->left)
		{
			s.push(cur->left);
		}
	}
	
}


//Alternate method
//print the cur and push its right child to stack

void printPreorderAL(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	stack<node*> s;
	node *cur = root;
	
	while(cur!=NULL || s.empty()==false)
	{
		while(cur!=NULL)
		{
			cout<<cur->data<<" ";
			if(cur->right)
			{
				s.push(cur->right);
			}
			cur = cur->left;
		}
		
		cur = s.top();
		s.pop();
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
	
	printPreorder(root);
	cout<<endl;
	printPreorderAL(root);
	
}
