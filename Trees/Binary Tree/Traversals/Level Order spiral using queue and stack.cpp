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


void printLevelOrder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	queue<node*> q;
	stack<int> s;
	bool reverse = true;
	
	q.push(root);
	while(!q.empty())
	{
		int size = q.size();
		while(size)
		{
		node *temp = q.front();
		q.pop();
		
		if(reverse)
		{
			s.push(temp->data);
		}
		else 
		{
			cout<<temp->data<<" ";
		}
		
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
		size--;
	}
	
	if(reverse)
	{
		while(!s.empty())
		{
			cout<<s.top()<<" ";
			s.pop();
		}
	}
	reverse = !reverse;
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
	
	printLevelOrder(root);
	
}
