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
	//take a deque
	deque<node*> d;
	d.push_back(root);
    //direction variable where 0 means right to left and 1 means left to right
    //will start from right to left
	int dir = 0; 
	
	while(!d.empty())
	{
		
		//take the current size of dequeue which will tell us how many nodes are there in the current level
		int size = d.size();
		
		//for all the nodes in the level, whether it will be left to right or right to left
		while(size--)
		{
			
			//so check direction
			if(dir==0)
			{
				
				//since it is right to left, take a node from right that is back, and will print one by one
				
				//but since we want the next level to be from left that is from front, we will push its child to front.
				
				node *temp = d.back();
				d.pop_back();
				
				//first push right child in case of right to left traversal and vice versa
				if(temp->right)
				{
					d.push_front(temp->right);
				}
				if(temp->left)
				{
					d.push_front(temp->left);
				}
				cout<<temp->data<<" ";
			}
			
			else
			{
				node *temp = d.front();
				d.pop_front();
				if(temp->left)
				{
					d.push_back(temp->left);
				}
				if(temp->right)
				{
					d.push_back(temp->right);
				}
				cout<<temp->data<<" ";
			}
		}
		
		dir=1-dir;
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
