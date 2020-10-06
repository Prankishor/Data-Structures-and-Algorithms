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

//Insert function (O(n))
node *insert(node *root, int key)
{
	if(root==NULL)
	{
		return new node(key);
	}
	if(key<root->data)
	{
		root->left = insert(root->left, key);
	}
	else if(key>root->data)
	{
		root->right = insert(root->right, key);
	}
	
	return root;
}

//search key function (O(log n))
bool search(node *root, int key)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data == key)
	{
		return true;
	}
	else if(key<root->data)
	{
		return search(root->left, key);
	}
	else
	{
		return search(root->right, key);
	}
}


node *KthSmallest(node *root, int &k)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	node *left = KthSmallest(root->left, k);
	if(left!=NULL)
	{
		return left;
	}
	k--;
	if(k==0)
	{
		return root;
	}
	
	return KthSmallest(root->right, k);

	
}

node *KthGreatest(node *root, int &k)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	node *right = KthGreatest(root->right, k);
	if(right!=NULL)
	{
		return right;
	}
	k--;
	if(k==0)
	{
		return root;
	}
	
	return KthGreatest(root->left, k);

	
}

int main()
{
	node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	printInorder(root);
	
	cout<<endl;
	int k=2;
	node *ans = KthSmallest(root, k);

	cout<<ans->data<<endl;
	int big=2;
    node *bigans = KthGreatest(root, big);
	cout<<bigans->data<<endl;
	
	
	//cout<<search(root, 10);
	
}
