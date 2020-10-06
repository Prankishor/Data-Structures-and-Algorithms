//O(N^2)

#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left, *right;
	node(char data)
	{
		this->data = data;
		left = right = NULL;
	}
};

int search(char in[], char c, int inS, int inE)
{
	for(int i=inS; i<=inE; i++)
	{
		if(in[i]==c)
		{
			return i;
		}
	}
	
}


node *buildTree(char *in, char *pre, int inS, int inE)
{
	//static is declared once, so the next line will only work on the first call. After that it wont work, preIndex will just go in incrementing because of below code.
	static int preIndex = 0;
	
	//inS > inE simply means empty.
	if(inS>inE)
	{
		return NULL;
	}
	
	//Here, we are constructing the binary tree. We know the root is always the first index of preorder. So we make the root in first call and follow
	//note we are incrementing preIndex after calling.
	node *tnode = new node(pre[preIndex++]);
	
	
	//Here, inS == inE means one element only, so we return that element
	if(inS==inE)
	{
		return tnode;
	}
	
	
	//Now we need to find the left subtree and right sub tree which we know can be formed from inorder array
	int inIndex = search(in, tnode->data, inS, inE);
	
	//constructing the left
	tnode->left = buildTree(in, pre, inS, inIndex-1);
	//constructing the right sub tree
	tnode->right = buildTree(in, pre, inIndex+1, inE);
	
	//returning to parent one by one after creating, left and right
	return tnode;
}

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

int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
    int len = sizeof(in) / sizeof(in[0]);  
    node* root = buildTree(in, pre, 0, len - 1);  
	cout << "Inorder traversal of the constructed tree is \n";  
    printInorder(root); 
	
}
