
//Won't run in Dev C++ cause doesn't support unordered_map. Try using gfg ide

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(char data)
	{
		this->data = data;
		left = right = NULL;
	}
};


node *buildTree(int *in, int *p, int inS, int inE, unordered_map<int, int> m)
{
	static int postIndex = inE;
	
	if(inS>inE)
	{
		return NULL;
	}
	
	node *tnode = new node(p[postIndex--]);
	
	if(inS==inE)
	{
		return tnode;
	}
	
	int inIndex = m[tnode->data];
	tnode->right = buildTree(in, p, inIndex+1, inE, m);
	tnode->left = buildTree(in, p, inS, inIndex-1, m);
	
	return tnode;
}

node *buildTreeWrap(int *in, int *p, int len)
{
	unordered_map<int, int> m;
	for(int i=0; i<len; i++)
	{
		m[in[i]] = i;
	}
	
	return buildTree(in, p, 0, len-1, m);
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
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };  
    int len = sizeof(in) / sizeof(in[0]);  
    node* root = buildTreeWrap(in, post, len);  
	cout << "Inorder traversal of the constructed tree is \n";  
    printInorder(root); 
	
}
