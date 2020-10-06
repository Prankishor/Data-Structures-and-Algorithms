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

void printLevelOrder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	map<int, vector<int> > m;
	queue<pair<node*, int> > q;
	int hd = 0;
	q.push(make_pair(root, hd));
	
	while(!q.empty())
	{
		pair<node*, int> temp = q.front();
		node *node= temp.first;
		hd = temp.second;
		m[hd].push_back(node->data);
		q.pop();
		
		if(node->left)
		{
			q.push(make_pair(node->left, hd-1));
		}
		
		if(node->right)
		{
			q.push(make_pair(node->right, hd+1));
			
		}
	}
	
	map<int, vector<int> > :: iterator it;
	
	for(it = m.begin(); it!=m.end(); it++)
	{
		for(int i=0; i<it->second.size(); i++)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
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
