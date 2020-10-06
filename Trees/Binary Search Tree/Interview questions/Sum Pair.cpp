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


bool sumPairUtil(node *root, int sum, set<int> &s)
{
	if(root==NULL)
	{
		return false;
	}
	
	if(sumPairUtil(root->left, sum, s))
	{
		return true;
	}
	
	if(s.find(sum-root->data)!=s.end())
	{
		return true;
	}
	else
	{
		s.insert(root->data);
	}
	return sumPairUtil(root->right, sum, s);
}

bool sumPair(node *root, int sum)
{
	set<int> s;
	
	return sumPairUtil(root, sum, s);

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
	cout<<sumPair(root, 100);
	
	
	
	
}
