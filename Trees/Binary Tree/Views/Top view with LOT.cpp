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



//Just keeping track of horizontal distance

void printBottomView(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	map<int, int> m;
	queue<pair<int, node*> > q;
	int hd = 0;
	q.push(make_pair(hd, root));
	map<int, int> :: iterator it;
	while(!q.empty())
	{
		pair<int, node*> temp = q.front();
		node *node= temp.second;
		hd = temp.first;
		if(m.find(hd) == m.end())
		{
			m[hd]= node->data;
		}
		q.pop();
		
		if(node->left)
		{
			q.push(make_pair(hd-1, node->left));
		}
		
		if(node->right)
		{
			q.push(make_pair(hd+1, node->right));
			
		}
	}
	
	
	
	for(it = m.begin(); it!=m.end(); it++)
	{
			cout<<it->second<<" ";
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
	
	printBottomView(root);
	
}
