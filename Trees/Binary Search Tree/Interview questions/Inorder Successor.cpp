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


node *IS(node *root, int key)
{
	node *temp = root;
	node *case2 = NULL;
	while(temp->data != key)
	{
		if(temp->data > key && temp->left)
		{
			case2 = temp;
			temp = temp->left;
		}
		else if(temp->data < key && temp->right)
		{
			
			temp = temp->right;
		}
		else
		{
			return NULL;
		}
		
	}
	
	if(temp == NULL)
	{
		return NULL;
	}
	else if(temp->left && temp->right)
	{
		temp = temp->right;
		while(temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}
	else
	{
		return case2;
	}
	
	
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
	
	node *ans = IS(root, 80);
	if(ans == NULL)
	{
		cout<<"No successor"<<endl;
	}
	else
	{
		cout<<ans->data<<endl;
	}
	
	
	//cout<<search(root, 10);
	
}
