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
node *LCA(node *root, int p, int q)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==p || root->data == q)
	{
		return root;
	}
	
	
	//we store the return nodes here from left and right sub trees cause, it is the calling function, root or NULL will get returned here
	node *left = LCA(root->left, p, q);
	node *right = LCA(root->right, p, q);
	
	
	//now if at any point of time in a node, we find that we have got both the nodes returned, we found the LCA
	if(left!=NULL && right!=NULL)
	{
		return root;
	}
	
	//else if left is present, return left, if not return right // This is just a way
	else
	{
		return left?left:right;
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
	root->left->right->left = new node(7);
	
	node *ans = LCA(root, 4, 7);
	cout<<ans->data<<endl;
	
}
