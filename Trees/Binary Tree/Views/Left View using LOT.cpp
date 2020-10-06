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


void printLeftView(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node *temp = q.front();
		if(temp!=NULL)
		{
			cout<<temp->data<<" ";
			
			while(q.front()!=NULL)
			{
				if(temp->left)
				{
					q.push(temp->left);
				}
				
				if(temp->right)
				{
					q.push(temp->right);
				}
				
				q.pop();
				temp = q.front();
			}
			
			q.push(NULL);
			
		}
		
		q.pop();
		
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
	
	printLeftView(root);
	
}
